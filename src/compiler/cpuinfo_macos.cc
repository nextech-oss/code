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
#if defined(CODE_HOST_OS_MACOS)

#include "src/cpuinfo.h"

#include <errno.h>       // NOLINT
#include <sys/sysctl.h>  // NOLINT
#include <sys/types.h>   // NOLINT

#include "platform/assert.h"

namespace Code {

CpuInfoMethod CpuInfo::method_ = kCpuInfoDefault;
const char* CpuInfo::fields_[kCpuInfoMax] = {};

void CpuInfo::Init() {
  method_ = kCpuInfoSystem;

  fields_[kCpuInfoProcessor] = "machdep.cpu.vendor";
  fields_[kCpuInfoModel] = "machdep.cpu.brand_string";
  fields_[kCpuInfoHardware] = "machdep.cpu.brand_string";
  fields_[kCpuInfoFeatures] = "machdep.cpu.features";
  fields_[kCpuInfoArchitecture] = nullptr;
}

void CpuInfo::Cleanup() {}

bool CpuInfo::FieldContains(CpuInfoIndices idx, const char* search_string) {
  ASSERT(method_ != kCpuInfoDefault);
  ASSERT(search_string != nullptr);
  const char* field = FieldName(idx);
  char dest[1024];
  size_t dest_len = 1024;

  ASSERT(HasField(field));
  if (sysctlbyname(field, dest, &dest_len, nullptr, 0) != 0) {
    UNREACHABLE();
    return false;
  }

  return (strcasestr(dest, search_string) != nullptr);
}

const char* CpuInfo::ExtractField(CpuInfoIndices idx) {
  ASSERT(method_ != kCpuInfoDefault);
  const char* field = FieldName(idx);
  ASSERT(field != nullptr);
  size_t result_len;

  ASSERT(HasField(field));
  if (sysctlbyname(field, nullptr, &result_len, nullptr, 0) != 0) {
    UNREACHABLE();
    return 0;
  }

  char* result = reinterpret_cast<char*>(malloc(result_len));
  if (sysctlbyname(field, result, &result_len, nullptr, 0) != 0) {
    UNREACHABLE();
    return 0;
  }

  return result;
}

bool CpuInfo::HasField(const char* field) {
  ASSERT(method_ != kCpuInfoDefault);
  ASSERT(field != nullptr);
  int ret = sysctlbyname(field, nullptr, nullptr, nullptr, 0);
  return (ret == 0);
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_MACOS)
