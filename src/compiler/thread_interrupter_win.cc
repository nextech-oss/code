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

#include "platform/globals.h"
#if defined(CODE_HOST_OS_WINDOWS)

#include "src/flags.h"
#include "src/os.h"
#include "src/profiler.h"
#include "src/thread_interrupter.h"

namespace Code {

#ifndef PRODUCT

DECLARE_FLAG(bool, trace_thread_interrupter);

#define kThreadError -1

class ThreadInterrupterWin : public AllStatic {
 public:
  static bool GrabRegisters(HANDLE handle, InterruptedThreadState* state) {
    CONTEXT context;
    memset(&context, 0, sizeof(context));
#if defined(HOST_ARCH_IA32)
    // On IA32, CONTEXT_CONTROL includes Eip, Ebp, and Esp.
    context.ContextFlags = CONTEXT_CONTROL;
#elif defined(HOST_ARCH_X64) || defined(HOST_ARCH_ARM) ||                      \
    defined(HOST_ARCH_ARM64)
    // On X64, CONTEXT_CONTROL includes Rip and Rsp. Rbp is classified
    // as an "integer" register.
    context.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
#else
#error Unsupported architecture.
#endif
    if (GetThreadContext(handle, &context) != 0) {
#if defined(HOST_ARCH_IA32)
      state->pc = static_cast<uintptr_t>(context.Eip);
      state->fp = static_cast<uintptr_t>(context.Ebp);
      state->csp = static_cast<uintptr_t>(context.Esp);
      state->dsp = static_cast<uintptr_t>(context.Esp);
      state->lr = 0;
#elif defined(HOST_ARCH_X64)
      state->pc = static_cast<uintptr_t>(context.Rip);
      state->fp = static_cast<uintptr_t>(context.Rbp);
      state->csp = static_cast<uintptr_t>(context.Rsp);
      state->dsp = static_cast<uintptr_t>(context.Rsp);
      state->lr = 0;
#elif defined(HOST_ARCH_ARM)
      state->pc = static_cast<uintptr_t>(context.Pc);
      state->fp = static_cast<uintptr_t>(context.R11);
      state->csp = static_cast<uintptr_t>(context.Sp);
      state->dsp = static_cast<uintptr_t>(context.Sp);
      state->lr = static_cast<uintptr_t>(context.R14);
#elif defined(HOST_ARCH_ARM64)
      state->pc = static_cast<uintptr_t>(context.Pc);
      state->fp = static_cast<uintptr_t>(context.Fp);
      state->csp = static_cast<uintptr_t>(context.Sp);
      state->dsp = static_cast<uintptr_t>(context.X15);
      state->lr = static_cast<uintptr_t>(context.Lr);
#else
#error Unsupported architecture.
#endif
      return true;
    }
    return false;
  }

  static void Interrupt(OSThread* os_thread) {
    ASSERT(!OSThread::Compare(GetCurrentThreadId(), os_thread->id()));
    HANDLE handle = OpenThread(
        THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION | THREAD_SUSPEND_RESUME,
        false, os_thread->id());
    ASSERT(handle != nullptr);
    DWORD result = SuspendThread(handle);
    if (result == kThreadError) {
      if (FLAG_trace_thread_interrupter) {
        OS::PrintErr("ThreadInterrupter failed to suspend thread %p\n",
                     reinterpret_cast<void*>(os_thread->id()));
      }
      CloseHandle(handle);
      return;
    }
    InterruptedThreadState its;
    if (!GrabRegisters(handle, &its)) {
      // Failed to get thread registers.
      ResumeThread(handle);
      if (FLAG_trace_thread_interrupter) {
        OS::PrintErr("ThreadInterrupter failed to get registers for %p\n",
                     reinterpret_cast<void*>(os_thread->id()));
      }
      CloseHandle(handle);
      return;
    }
    // Currently we sample only threads that are associated
    // with an isolate. It is safe to call 'os_thread->thread()'
    // here as the thread which is being queried is suspended.
    Thread* thread = static_cast<Thread*>(os_thread->thread());
    if (thread != nullptr) {
      ThreadInterruptScope signal_handler_scope;
      Profiler::SampleThread(thread, its);
    }
    ResumeThread(handle);
    CloseHandle(handle);
  }
};

void ThreadInterrupter::InterruptThread(OSThread* thread) {
  if (FLAG_trace_thread_interrupter) {
    OS::PrintErr("ThreadInterrupter suspending %p\n",
                 reinterpret_cast<void*>(thread->id()));
  }
  ThreadInterrupterWin::Interrupt(thread);
  if (FLAG_trace_thread_interrupter) {
    OS::PrintErr("ThreadInterrupter resuming %p\n",
                 reinterpret_cast<void*>(thread->id()));
  }
}

void ThreadInterrupter::InstallSignalHandler() {
  // Nothing to do on Windows.
}

void ThreadInterrupter::RemoveSignalHandler() {
  // Nothing to do on Windows.
}

#endif  // !PRODUCT

}  // namespace dart

#endif  // defined(CODE_HOST_OS_WINDOWS)
