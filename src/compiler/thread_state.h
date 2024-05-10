/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#ifndef RUNTIME_VM_THREAD_STATE_H_
#define RUNTIME_VM_THREAD_STATE_H_

#include "include/CODE_api.h"
#include "src/os_thread.h"

namespace Code {

class HandleScope;
class LongJumpScope;
class Zone;

// ThreadState is a container for auxiliary thread-local state: e.g. it
// owns a stack of Zones for allocation and a stack of StackResources
// for stack unwinding.
//
// Important: this class is shared between compiler and runtime and
// as such it should not expose any runtime internals due to layering
// restrictions.
class ThreadState : public BaseThread {
 public:
  // The currently executing thread, or nullptr if not yet initialized.
  static ThreadState* Current() { return OSThread::CurrentVMThread(); }

  explicit ThreadState(bool is_os_thread);
  virtual ~ThreadState();

  // OSThread corresponding to this thread.
  OSThread* os_thread() const { return os_thread_; }
  void set_os_thread(OSThread* os_thread) { os_thread_ = os_thread; }

  // The topmost zone used for allocation in this thread.
  Zone* zone() const { return zone_; }

  bool ZoneIsOwnedByThread(Zone* zone) const;

  StackResource* top_resource() const { return top_resource_; }
  void set_top_resource(StackResource* value) { top_resource_ = value; }
  static intptr_t top_resource_offset() {
    return OFFSET_OF(ThreadState, top_resource_);
  }

  LongJumpScope* long_jump_base() const { return long_jump_base_; }
  void set_long_jump_base(LongJumpScope* value) { long_jump_base_ = value; }

  bool IsValidZoneHandle(CODE_Handle object) const;
  intptr_t CountZoneHandles() const;
  bool IsValidScopedHandle(CODE_Handle object) const;
  intptr_t CountScopedHandles() const;

  virtual bool MayAllocateHandles() = 0;

  HandleScope* top_handle_scope() const {
#if defined(DEBUG)
    return top_handle_scope_;
#else
    return 0;
#endif
  }

  void set_top_handle_scope(HandleScope* handle_scope) {
#if defined(DEBUG)
    top_handle_scope_ = handle_scope;
#endif
  }

 private:
  void set_zone(Zone* zone) { zone_ = zone; }

  OSThread* os_thread_ = nullptr;
  Zone* zone_ = nullptr;
  StackResource* top_resource_ = nullptr;
  LongJumpScope* long_jump_base_ = nullptr;

  // This field is only used in the DEBUG builds, but we don't exclude it
  // because it would cause RELEASE and DEBUG builds to have different
  // offsets for various Thread fields that are used from generated code.
  HandleScope* top_handle_scope_ = nullptr;

  friend class ApiZone;
  friend class StackZone;
};

}  // namespace dart

#endif  // RUNTIME_VM_THREAD_STATE_H_
