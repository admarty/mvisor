/* 
 * MVisor - Sweet Connection
 * Copyright (C) 2022 Terrence <terrence@tenclass.com>
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

#include "server.h"
#include "connection.h"
#include "display_encoder.h"
#include "utilities.h"
#include "logger.h"
#include "sweet.pb.h"

#include <libyuv.h>
#include <jpeglib.h>


SweetConnection::SweetConnection(SweetServer* server, int fd) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  server_ = server;
  machine_ = server->machine();
  fd_ = fd;
}

SweetConnection::~SweetConnection() {
  safe_close(&fd_);
}

bool SweetConnection::OnReceive() {
  SweetPacketHeader header;
  int nbytes = recv(fd_, &header, sizeof(header), MSG_WAITALL);
  if (nbytes <= 0) {
    return false;
  }
  
  ParsePacket(&header);
  return true;
}

void SweetConnection::ParsePacket(SweetPacketHeader* header) {
  if (header->length) {
    buffer_.resize(header->length);
    int ret = recv(fd_, buffer_.data(), header->length, MSG_WAITALL);
    if (ret != (int)header->length) {
      MV_ERROR("failed to recv %u bytes, ret=%d", header->length, ret);
      return;
    }
  }

  switch (header->type)
  {
  case kQueryStatus:
    OnQueryStatus();
    break;
  case kPauseMachine:
    machine_->Pause();
    break;
  case kResumeMachine:
    machine_->Resume();
    break;
  case kResetMachine:
    machine_->Reset();
    break;
  case kShutdownMachine:
    machine_->Shutdown();
    break;
  case kQuitMachine:
    machine_->Quit();
    break;
  case kSaveMachine:
    OnSaveMachine();
    break;
  case kMigrateMachine:
    OnMigrateMachine();
    break;
  case kPostMigrateMachine:
    OnPostMigrateMachine();
    break;
  case kQemuGuestCommand:
    server_->QemuGuestCommand(this, buffer_);
    break;
  case kStartDisplayStream:
    OnStartDisplayStream();
    break;
  case kStopDisplayStream:
    server_->StopDisplayStream();
    break;
  case kRefreshDisplayStream:
    server_->RefreshDisplayStream();
    break;
  case kSendKeyboardInput:
    OnKeyboardInput();
    break;
  case kSendPointerInput:
    OnSendPointerInput();
    break;
  case kSendMotionInput:
    OnSendMotionInput();
    break;
  case kConfigMonitors:
    OnConfigMonitors();
    break;
  case kStartPlaybackStream:
    OnStartPlaybackStream();
    break;
  case kStopPlaybackStream:
    server_->StopPlaybackStream();
    break;
  case kQueryScreenshot:
    OnQueryScreenshot();
    break;
  case kStartRecordStream:
    OnStartRecordStream();
    break;
  case kStopRecordStream:
    OnStopRecordStream();
    break;
  case kSendRecordStreamData:
    OnSendRecordStreamData();
    break;
  case kClipboardDataToGuest:
    OnClipboardDataToGuest();
    break;
  case kStartClipboardStream:
    OnStartClipboardStream();
    break;
  case kStopClipboardStream:
    OnStopClipboardStream();
    break;
  case kStartVirtioFs:
    OnStartVirtioFs();
    break;
  case kStopVirtioFs:
    OnStopVirtioFs();
    break;
  case kStartMidi:
    OnStartMidi();
    break;
  case kStopMidi:
    OnStopMidi();
    break;
  case kSendMidiInput:
    OnMidiInput();
    break;
  case kStartWacom:
    OnStartWacom();
    break;
  case kStopWacom:
    OnStopWacom();
    break;
  case kSendWacomInput:
    OnWacomInput();
    break;

  default:
    MV_ERROR("unhandled sweet type=0x%x", header->type);
    return;
  }

  /* command acknowledge */
  Send(kCommandAcknowledge);
}

bool SweetConnection::Send(uint32_t type, void* data, size_t length) {
  SweetPacketHeader header = {
    .type = type,
    .length = (uint32_t)length,
    .flags = 0,
    .reserved = 0
  };
  int ret = send(fd_, &header, sizeof(header), 0);
  if (ret != sizeof(header)) {
    MV_ERROR("failed to send message, type=0x%x ret=%d", type, ret);
    return false;
  }

  if (length > 0) {
    ret = send(fd_, data, length, 0);
    if (ret != (int)length) {
      MV_ERROR("failed to send message, type=0x%x ret=%d", type, ret);
      return false;
    }
  }
  return true;
}

bool SweetConnection::Send(uint32_t type, const std::string& data) {
  return Send(type, (void*)data.data(), data.size());
}

bool SweetConnection::Send(uint32_t type, const Message& message) {
  /* Reuse the buffer */
  if (!message.SerializeToString(&buffer_)) {
    MV_ERROR("failed to serialize message type=0x%x", type);
    return false;
  }
  return Send(type, buffer_.data(), buffer_.size());
}

bool SweetConnection::Send(uint32_t type) {
  return Send(type, nullptr, 0);
}

void SweetConnection::OnQueryStatus() {
  QueryStatusResponse response;  
  response.set_debug(machine_->debug());
  response.set_status(machine_->GetStatus());
  response.set_hypervisor(machine_->hypervisor());
  response.set_vcpu_count(machine_->num_vcpus());
  response.set_memory_size(machine_->ram_size());
  response.set_vm_uuid(machine_->vm_uuid());
  response.set_vm_name(machine_->vm_name());
  response.set_config_path(machine_->configuration()->path());

  auto spice_agent = dynamic_cast<SerialPortInterface*>(machine_->LookupObjectByClass("SpiceAgent"));
  if (spice_agent && spice_agent->ready()) {
    response.set_spice_agent(true);
  }
  auto qemu_agent = dynamic_cast<SerialPortInterface*>(machine_->LookupObjectByClass("QemuGuestAgent"));
  if (qemu_agent && qemu_agent->ready()) {
    response.set_qemu_agent(true);
  }

  Send(kQueryStatusResponse, response);
}

void SweetConnection::OnSaveMachine() {
  SaveMachineOptions options;
  if (!options.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  machine_->Save(options.path());
}

void SweetConnection::OnMigrateMachine() {
  MigrateMachineOptions options;
  if (!options.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }

  std::thread([=]() {
    MigrateResponse response;
    auto ret = machine_->Save(options.ip(), options.port());
    response.set_status(ret ? "migrating" : "error");
    Send(kMigrateMachineEvent, response);
  }).detach();
}

void SweetConnection::OnPostMigrateMachine() {
  std::thread([=]() {
    MigrateResponse response;
    auto ret = machine_->PostSave();
    response.set_status(ret ? "done" : "error");
    Send(kPostMigrateMachineEvent, response);
  }).detach();
}

void SweetConnection::OnKeyboardInput() {
  SendKeyboardInput input;
  if (!input.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  if (machine_->IsPaused()) {
    return;
  }

  uint code = input.scancode();
  uint8_t scancode[10] = { 0 };
  for (int i = 0; i < 10 && code; i++) {
    scancode[i] = (uint8_t)code;
    code >>= 8;
  }

  auto keyboard = server_->keyboard();
  if (keyboard->InputAcceptable()) {
    keyboard->QueueKeyboardEvent(scancode, input.modifiers());
  }
}

void SweetConnection::OnSendPointerInput() {
  SendPointerInput input;
  if (!input.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  if (machine_->IsPaused()) {
    return;
  }

  PointerEvent event;
  event.buttons = input.buttons();
  event.x = input.x();
  event.y = input.y();
  event.z = input.z();

  int w, h;
  server_->display()->GetDisplayMode(&w, &h, nullptr, nullptr);
  event.screen_width = w;
  event.screen_height = h;
  
  for (auto pointer : server_->pointers()) {
    if (pointer->InputAcceptable()) {
      pointer->QueuePointerEvent(event);
      break;
    }
  }
}

void SweetConnection::OnSendMotionInput() {
  SendMotionInput input;
  if (!input.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  if (machine_->IsPaused()) {
    return;
  }

  auto keyboard = server_->keyboard();
  if (keyboard->InputAcceptable()) {
    keyboard->QueueMouseEvent(input.button_state(), input.rel_x(), input.rel_y(), input.rel_z());
  }
}

void SweetConnection::OnConfigMonitors() {
  MonitorsConfig config;
  if (!config.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  
  MV_ASSERT(config.count() > 0);
  auto& monitor = config.monitors(0);

  for (auto resizer : server_->resizers()) {
    if (resizer->Resize(monitor.width(), monitor.height())) {
      break;
    }
  }
}

void SweetConnection::OnStartDisplayStream() {
  DisplayStreamConfig config;
  if (!config.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  server_->StartDisplayStreamOnConnection(this, &config);
}

void SweetConnection::OnStartPlaybackStream() {
  PlaybackStreamConfig config;
  if (!config.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  server_->StartPlaybackStreamOnConnection(this, &config);
}

void SweetConnection::SendDisplayStreamStartEvent(uint w, uint h) {
  DisplayStreamStartEvent event;
  event.set_width(w);
  event.set_height(h);
  Send(kDisplayStreamStartEvent, event);
}

void SweetConnection::UpdateCursor(const DisplayMouseCursor* cursor_update) {
  if (cursor_update->visible) {
    if (cursor_update->shape.id == cursor_shape_id_) {
      return;
    }
    auto& shape = cursor_update->shape;

    cursor_shape_id_ = shape.id;
    cursor_visible_ = true;

    SetCursorEvent event;
    event.set_visible(true);
    event.set_x(cursor_update->x);
    event.set_y(cursor_update->y);
    auto cursor = event.mutable_shape();
    cursor->set_type(shape.type);
    cursor->set_width(shape.width);
    cursor->set_height(shape.height);
    cursor->set_hotspot_x(shape.hotspot_x);
    cursor->set_hotspot_y(shape.hotspot_y);

    cursor->set_data(shape.data.data(), shape.data.size());
    Send(kSetCursorEvent, event);
  } else {
    if (cursor_visible_) {
      cursor_visible_ = false;
  
      SetCursorEvent event;
      event.set_visible(false);
      Send(kSetCursorEvent, event);
    }
  }
}

void SweetConnection::SendPlaybackStreamStartEvent(std::string codec, uint format, uint channels, uint frequency) {
  PlaybackStreamStartEvent event;
  event.set_codec(codec);
  event.set_format(format);
  event.set_channels(channels);
  event.set_frequency(frequency);
  Send(kPlaybackStreamStartEvent, event);
}

void SweetConnection::SendClipboardStreamDataEvent(const ClipboardData& clipboard_data) {
  ClipboardStreamDataEvent event;
  event.set_type(SweetProtocol::ClipboardDataType(clipboard_data.type));
  event.set_data(clipboard_data.data);
  Send(kClipboardStreamDataEvent, event);
}

void SweetConnection::SendSerialPortStatusEvent(std::string name, bool ready) {
  SerialPortStatusEvent event;
  event.set_port_name(name);
  event.set_ready(ready);
  Send(kSerialPortStatusEvent, event);
}

void SweetConnection::OnQueryScreenshot() {
  QueryScreeenshot query;
  if (!query.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  if (query.format() != "jpeg") {
    MV_ERROR("not supported screendump format %s", query.format().c_str());
    return;
  }

  /* Get the full picture of the display output */
  DisplayUpdate update;
  auto display = server_->display();
  if (!display->AcquireUpdate(update, true)) {
    MV_ERROR("failed to acquire display update");
    return;
  }

  if (update.partials.empty()) {
    MV_ERROR("failed to get display update");
    display->ReleaseUpdate();
    return;
  }

  auto &partial = update.partials.front();
  int w = query.width();
  int h = query.height();

  if (!w && !h) {
    w = partial.width;
    h = partial.height;
  } else if (!w) {
    w = h * partial.width / partial.height;
  } else if (!h) {
    h = w * partial.height / partial.width;
  }

  if (w < 16 || w > partial.width)
    w = partial.width;
  if (h < 16 || h > partial.height)
    h = partial.height;


  /* Scale screen bitmap to w x h */
  size_t bitmap_stride = w * 4;
  uint8_t* bitmap = new uint8_t[bitmap_stride * h];
  if (partial.bpp == 32) {
    libyuv::ARGBScale(partial.data, partial.stride, partial.width, partial.height,
      bitmap, bitmap_stride, w, h, libyuv::kFilterBilinear);
  } else if (partial.bpp == 24) {
    int argb_stride = partial.width * 4;
    uint8_t* argb = new uint8_t[argb_stride * partial.height];
    libyuv::RGB24ToARGB(partial.data, partial.stride, argb, argb_stride, partial.width, partial.height);
    libyuv::ARGBScale(argb, argb_stride, partial.width, partial.height,
      bitmap, bitmap_stride, w, h, libyuv::kFilterBilinear);
    delete[] argb;
  } else {
    /* other bpp not supported yet */
    bzero(bitmap, bitmap_stride * h);
  }
  
  display->ReleaseUpdate();

  /* bitmap to jpeg */
  jpeg_compress_struct cinfo;
  jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);

  uint8_t* out_buffer = nullptr;
  size_t out_size = 0;
  jpeg_mem_dest(&cinfo, &out_buffer, &out_size);

  cinfo.image_width = w;
  cinfo.image_height = h;
  cinfo.input_components = 4;
  cinfo.in_color_space = JCS_EXT_BGRA;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, 80, true);
  jpeg_start_compress(&cinfo, true);
  while (cinfo.next_scanline < cinfo.image_height) {
    JSAMPROW row_pointer = bitmap + cinfo.next_scanline * bitmap_stride;
    jpeg_write_scanlines(&cinfo, &row_pointer, 1);
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);
  delete[] bitmap;
  
  if (out_buffer) {
    QueryScreenshotResponse response;
    response.set_format(query.format());
    response.set_width(query.width());
    response.set_height(query.height());
    response.set_data(out_buffer, out_size);
    Send(kQueryScreenshotResponse, response);
    free(out_buffer);
  }
}

void SweetConnection::OnClipboardDataToGuest() {
  ClipboardDataToGuest clipboard;
  if(!clipboard.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }

  auto clipboard_interface = server_->clipboard();
  MV_ASSERT(clipboard_interface);

  switch(clipboard.type()) {
    case kSweetClipboard_UTF8_TEXT:
      clipboard_interface->ClipboardDataToGuest(clipboard.type(), clipboard.data());
      break;
    case kSweetClipboard_NONE:
    case kSweetClipboard_IMAGE_PNG:
    case kSweetClipboard_IMAGE_BMP:
    case kSweetClipboard_IMAGE_TIFF:
    case kSweetClipboard_IMAGE_JPG:
    case kSweetClipboard_FILE_LIST:
    default:
      MV_ERROR("sweet clipboard data type 0x%x not implemented", clipboard.type());
      break;
  }
}

void SweetConnection::OnStartClipboardStream() {
  if(server_) {
    server_->StartClipboardStreamOnConnection(this);
  }
}

void SweetConnection::OnStopClipboardStream() {
  if(server_) {
    server_->StopClipboardStream();
  }
}
void SweetConnection::OnStartVirtioFs() {
  server_->StartVirtioFsConnection(this);
}

void SweetConnection::OnStopVirtioFs() {
  server_->StopVirtioFsConnection();
}

void SweetConnection::OnMidiInput() {
  if (machine_->IsPaused()) {
    return;
  }
  auto midi = server_->midi();
  if(!midi || !midi->InputAcceptable()) {
    return;
  }

  SendMidiInput input;
  if (!input.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }

  MidiEvent event;
  event.midi_0 = input.midi_0();
  event.midi_1 = input.midi_1();
  event.midi_2 = input.midi_2();
  event.cable_code_index = input.cable_code_index();
  midi->QueueMidiEvent(event);
}

void SweetConnection::OnWacomInput() {
  if (machine_->IsPaused()) {
    return;
  }

  auto wacom = server_->wacom();
  if(!wacom || !wacom->InputAcceptable()) {
    return;
  }

  SendWacomInput input;
  if (!input.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }
  
  WacomEvent event;
  event.x = input.x();
  event.y = input.y();
  event.buttons = input.buttons();
  event.pressure = input.pressure();
  event.tilt_x = input.tilt_x();
  event.tilt_y = input.tilt_y();
  wacom->QueueWacomEvent(event);
}

void SweetConnection::OnStartMidi() {
  server_->StartMidiConnection(this);
  auto midi = server_->midi();
  if(midi) {
    midi->Start();
  }
}

void SweetConnection::OnStopMidi() {
  server_->StopMidiConnection();
  auto midi = server_->midi();
  if(midi) {
    midi->Stop();
  }
}

void SweetConnection::OnStartWacom() {
  server_->StartWacomConnection(this);
  auto wacom = server_->wacom();
  if(wacom) {
    wacom->Start();
  }
}

void SweetConnection::OnStopWacom() {
  server_->StopWacomConnection();
  auto wacom = server_->wacom();
  if(wacom) {
    wacom->Stop();
  }
}
void SweetConnection::OnStartRecordStream() {
  RecordStreamConfig record_config;
  if(!record_config.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }

  server_->StartRecordStreamOnConnection(this, &record_config);
}

void SweetConnection::OnStopRecordStream() {
  server_->StopRecordStream();
}

void SweetConnection::OnSendRecordStreamData() {
  SendRecordStreamData record_data;
  if(!record_data.ParseFromString(buffer_)) {
    MV_ERROR("failed to parse buffer");
    return;
  }

  server_->SendRecordStreamData(record_data.data());
}
