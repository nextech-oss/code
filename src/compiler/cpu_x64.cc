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

#include "src/globals.h"
#if defined(TARGET_ARCH_X64)

#include "src/cpu.h"
#include "src/cpu_x64.h"

#include "src/cpuinfo.h"

namespace Code {

DEFINE_FLAG(bool, use_sse41, true, "Use SSE 4.1 if available");

void CPU::FlushICache(uword start, uword size) {
  // Nothing to be done here.
}

const char* CPU::Id() {
  return
#if defined(USING_SIMULATOR)
      "sim"
#endif  // !defined(USING_SIMULATOR)
      "x64";
}

const char* HostCPUFeatures::hardware_ = nullptr;
bool HostCPUFeatures::sse2_supported_ = true;
bool HostCPUFeatures::sse4_1_supported_ = false;
bool HostCPUFeatures::popcnt_supported_ = false;
bool HostCPUFeatures::abm_supported_ = false;

#if defined(DEBUG)
bool HostCPUFeatures::initialized_ = false;
#endif

#if !defined(USING_SIMULATOR)
void HostCPUFeatures::Init() {
  CpuInfo::Init();
  hardware_ = CpuInfo::GetCpuModel();
  sse4_1_supported_ = CpuInfo::FieldContains(kCpuInfoFeatures, "sse4_1") ||
                      CpuInfo::FieldContains(kCpuInfoFeatures, "sse4.1");
  popcnt_supported_ = CpuInfo::FieldContains(kCpuInfoFeatures, "popcnt");
  abm_supported_ = CpuInfo::FieldContains(kCpuInfoFeatures, "abm");
#if defined(DEBUG)
  initialized_ = true;
#endif
}

void HostCPUFeatures::Cleanup() {
  DEBUG_ASSERT(initialized_);
#if defined(DEBUG)
  initialized_ = false;
#endif
  ASSERT(hardware_ != nullptr);
  free(const_cast<char*>(hardware_));
  hardware_ = nullptr;
  CpuInfo::Cleanup();
}

#else  // !defined(USING_SIMULATOR)

void HostCPUFeatures::Init() {
  CpuInfo::Init();
  hardware_ = CpuInfo::GetCpuModel();
  sse4_1_supported_ = false;
  popcnt_supported_ = false;
  abm_supported_ = false;
#if defined(DEBUG)
  initialized_ = true;
#endif
}

void HostCPUFeatures::Cleanup() {
  DEBUG_ASSERT(initialized_);
#if defined(DEBUG)
  initialized_ = false;
#endif
  ASSERT(hardware_ != nullptr);
  free(const_cast<char*>(hardware_));
  hardware_ = nullptr;
  CpuInfo::Cleanup();
}
#endif  // !defined(USING_SIMULATOR)

}  // namespace dart

#endif  // defined TARGET_ARCH_X64
