/* 
 * MVisor VirtIO Block Device
 * Copyright (C) 2021 Terrence <terrence@tenclass.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "virtio_pci.h"
#include <cstring>
#include <cmath>
#include "linux/virtio_blk.h"
#include "logger.h"
#include "disk_image.h"
#include "machine.h"

#define DEFAULT_QUEUE_SIZE 256

class VirtioBlock : public VirtioPci {
 private:
  virtio_blk_config block_config_;
  DiskImage* image_ = nullptr;

 public:
  VirtioBlock() {
    devfn_ = PCI_MAKE_DEVFN(6, 0);
    pci_header_.class_code = 0x010000;
    pci_header_.device_id = 0x1001;
    pci_header_.subsys_id = 0x0002;
    
    AddMsiXCapability(1, 2);

    device_features_ |= (1UL << VIRTIO_BLK_F_SEG_MAX) |
      // (1UL << VIRTIO_BLK_F_GEOMETRY) |
      (1UL << VIRTIO_BLK_F_BLK_SIZE) |
      (1UL << VIRTIO_BLK_F_FLUSH) |
      // (1UL << VIRTIO_BLK_F_TOPOLOGY) |
      (1UL << VIRTIO_BLK_F_WCE) |
      (1UL << VIRTIO_BLK_F_MQ) |
      // FIXME: DISCARD & WRITE_ZERO needs latest guest drivers
      (1UL << VIRTIO_BLK_F_DISCARD) |
      (1UL << VIRTIO_BLK_F_WRITE_ZEROES);
    bzero(&block_config_, sizeof(block_config_));
  }

  virtual void Disconnect() {
    VirtioPci::Disconnect();
    if (image_) {
      delete image_;
      image_ = nullptr;
    }
  }

  virtual void Connect() {
    VirtioPci::Connect();

    /* Connect to backend image */
    bool readonly = false;
    if (has_key("readonly")) {
      readonly = std::get<bool>(key_values_["readonly"]);
    }
    if (has_key("image")) {
      std::string path = std::get<std::string>(key_values_["image"]);
      image_ = DiskImage::Create(path, readonly);
    }
    if (image_) {
      InitializeGeometry();
      if (readonly) {
        device_features_ |= VIRTIO_BLK_F_RO;
      }
    }
  }

  void InitializeGeometry() {
    auto information = image_->information();
    block_config_.capacity = information.total_blocks;
    block_config_.blk_size = information.block_size;

    block_config_.num_queues = manager_->machine()->num_vcpus();
    block_config_.seg_max = DEFAULT_QUEUE_SIZE - 2;
    block_config_.wce = 1; // write back (enable cache)
    block_config_.max_discard_sectors = __INT_MAX__ / block_config_.blk_size;
    block_config_.max_discard_seg = 1;
    block_config_.discard_sector_alignment = 1;
    block_config_.max_write_zeroes_sectors = block_config_.max_discard_sectors;
    block_config_.max_write_zeroes_seg = block_config_.max_discard_seg;
    block_config_.write_zeroes_may_unmap = 1;
  }

  void Reset() {
    /* Reset all queues */
    VirtioPci::Reset();
  
    for (int i = 0; i < block_config_.num_queues; ++i) {
      AddQueue(DEFAULT_QUEUE_SIZE, std::bind(&VirtioBlock::OnOutput, this, i));
    }
  }

  void ReadDeviceConfig(uint64_t offset, uint8_t* data, uint32_t size) {
    MV_ASSERT(offset + size <= sizeof(block_config_));
    memcpy(data, (uint8_t*)&block_config_ + offset, size);
  }

  void OnOutput(int queue_index) {
    auto &vq = queues_[queue_index];
    VirtElement element;
  
    while (PopQueue(vq, element)) {
      HandleCommand(vq, element);
      PushQueue(vq, element);
      NotifyQueue(vq);
    }
  }

  void HandleCommand(VirtQueue& vq, VirtElement& element) {
    auto &vector = element.vector;
    /* Read block header */
    virtio_blk_outhdr* request = (virtio_blk_outhdr*)vector.front().iov_base;
    vector.pop_front();

    /* Get status header at the end of vector, currently only 1 byte */
    uint8_t* status = (uint8_t*)vector.back().iov_base;
    MV_ASSERT(vector.back().iov_len == 1);
    vector.pop_back();

    /* Set the vring data length to bytes returned */
    element.length = sizeof(*status);

    switch (request->type)
    {
    case VIRTIO_BLK_T_IN: {
      size_t position = request->sector * block_config_.blk_size;
      for (auto &iov : vector) {
        void* buffer = iov.iov_base;
        size_t length = iov.iov_len;
        ssize_t bytes = image_->Read(buffer, position, length);
        if (bytes != (ssize_t)length) {
          MV_PANIC("failed read bytes=%lx pos=%lx length=%lx", bytes, position, length);
        }
        position += length;
        element.length += length;
      }
      *status = 0;
      break;
    }
    case VIRTIO_BLK_T_OUT: {
      size_t position = request->sector * block_config_.blk_size;
      for (auto &iov : vector) {
        void* buffer = iov.iov_base;
        size_t length = iov.iov_len;
        ssize_t bytes = image_->Write(buffer, position, length);
        if (bytes <= 0) {
          break;
        }
        position += bytes;
      }
      *status = 0;
      break;
    }
    case VIRTIO_BLK_T_FLUSH:
      image_->Flush();
      *status = 0;
      break;
    case VIRTIO_BLK_T_GET_ID: {
      auto &iov = vector.front();
      void* buffer = iov.iov_base;
      MV_ASSERT(iov.iov_len >= 20);

      strcpy((char*)buffer, "virtio-block");
      element.length += iov.iov_len;
      *status = 0;
      break;
    }
    default:
      MV_PANIC("unhandled command type=0x%x", request->type);
      break;
    }
  }
};

DECLARE_DEVICE(VirtioBlock);
