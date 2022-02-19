/* 
 * MVisor
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

#ifndef _MVISOR_IO_THREAD_H
#define _MVISOR_IO_THREAD_H

#include <liburing.h>
#include <thread>
#include <functional>
#include <chrono>
#include <unordered_set>
#include <mutex>

typedef std::function<void(uint)> EventsCallback;
typedef std::function<void()> IoCallback;
typedef std::chrono::steady_clock::time_point IoTimePoint;

struct IoTimer {
  bool          permanent;
  int           interval_ms;
  IoTimePoint   next_timepoint;
  IoCallback    callback;
};

enum IoRequestType {
  kIoRequestPoll,
  kIoRequestRead,
  kIoRequestWrite
};

struct IoRequest {
  enum IoRequestType  type;
  int                 fd;
  uint                poll_mask;
  EventsCallback      callback;
  bool                removed;
};

class Machine;

class IoThread {
 public:
  IoThread(Machine* machine);
  ~IoThread();
  void Start();
  void Stop();

  IoRequest* Read(int fd, void* buffer, size_t bytes, off_t offset, EventsCallback callback);
  IoRequest* Write(int fd, void* buffer, size_t bytes, off_t offset, EventsCallback callback);
  IoRequest* StartPolling(int fd, uint poll_mask, EventsCallback callback);
  void ModifyPolling(IoRequest* request, uint poll_mask);
  void StopPolling(IoRequest* request);
  void StopPolling(int fd);

  IoTimer* AddTimer(int interval_ms, bool permanent, IoCallback callback);
  void RemoveTimer(IoTimer* timer);
  void ModifyTimer(IoTimer* timer, int interval_ms);
  void Schedule(IoCallback callback);

 private:
  void RunLoop();
  int CheckTimers();

  std::thread           thread_;
  Machine*              machine_;
  struct io_uring       ring_;
  std::recursive_mutex  mutex_;
  std::unordered_set<IoTimer*>    timers_;
  std::unordered_set<IoRequest*>  requests_;
};

#endif // _MVISOR_IO_THREAD_H
