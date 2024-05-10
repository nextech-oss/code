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
#if !defined(CODE_PRECOMPILED_RUNTIME)

#include "src/kernel_binary.h"

#include <memory>

#include "platform/globals.h"
#include "src/compiler/frontend/kernel_to_il.h"
#include "src/CODE_api_impl.h"
#include "src/flags.h"
#include "src/growable_array.h"
#include "src/kernel.h"
#include "src/object.h"
#include "src/os.h"
#include "src/version.h"

namespace Code {

namespace kernel {

const char* Reader::TagName(Tag tag) {
  switch (tag) {
#define CASE(Name, value)                                                      \
  case k##Name:                                                                \
    return #Name;
    KERNEL_TAG_LIST(CASE)
#undef CASE
    default:
      break;
  }
  return "Unknown";
}

TypedDataPtr Reader::ReadLineStartsData(intptr_t line_start_count) {
  const intptr_t start_offset = offset();

  // Choose representation between Uint16 and Uint32 typed data.
  intptr_t max_start = 0;
  for (intptr_t i = 0; i < line_start_count; ++i) {
    const intptr_t delta = ReadUInt();
    max_start += delta;
  }

  const intptr_t cid = (max_start <= kMaxUint16) ? kTypedDataUint16ArrayCid
                                                 : kTypedDataUint32ArrayCid;
  const TypedData& line_starts_data =
      TypedData::Handle(TypedData::New(cid, line_start_count, Heap::kOld));

  set_offset(start_offset);
  intptr_t current_start = 0;
  for (intptr_t i = 0; i < line_start_count; ++i) {
    const intptr_t delta = ReadUInt();
    current_start += delta;
    if (cid == kTypedDataUint16ArrayCid) {
      line_starts_data.SetUint16(i << 1, static_cast<uint16_t>(current_start));
    } else {
      line_starts_data.SetUint32(i << 2, current_start);
    }
  }

  return line_starts_data.ptr();
}

const char* kKernelInvalidFilesize =
    "File size is too small to be a valid kernel file";
const char* kKernelInvalidMagicIdentifier = "Invalid magic identifier";
const char* kKernelInvalidBinaryFormatVersion =
    "Invalid kernel binary format version";
const char* kKernelInvalidSizeIndicated =
    "Invalid kernel binary: Indicated size is invalid";
const char* kKernelInvalidSdkHash = "Invalid SDK hash";

const int kSdkHashSizeInBytes = 10;
const char* kSdkHashNull = "0000000000";

bool IsValidSdkHash(const uint8_t* sdk_hash) {
  if (memcmp(Version::SdkHash(), kSdkHashNull, kSdkHashSizeInBytes) != 0 &&
      memcmp(sdk_hash, kSdkHashNull, kSdkHashSizeInBytes) != 0 &&
      memcmp(sdk_hash, Version::SdkHash(), kSdkHashSizeInBytes) != 0) {
    return false;
  }
  return true;
}

std::unique_ptr<Program> Program::ReadFrom(Reader* reader, const char** error) {
  if (reader->size() < 70) {
    // A kernel file (v43) currently contains at least the following:
    //   * Magic number (32)
    //   * Kernel version (32)
    //   * SDK Hash (10 * 8)
    //   * List of problems (8)
    //   * Length of source map (32)
    //   * Length of canonical name table (8)
    //   * Metadata length (32)
    //   * Length of string table (8)
    //   * Length of constant table (8)
    //   * Component index (11 * 32)
    //
    // so is at least 74 bytes.
    // (Technically it will also contain an empty entry in both source map and
    // string table, taking up another 8 bytes.)
    if (error != nullptr) {
      *error = kKernelInvalidFilesize;
    }
    return nullptr;
  }

  uint32_t magic = reader->ReadUInt32();
  if (magic != kMagicProgramFile) {
    if (error != nullptr) {
      *error = kKernelInvalidMagicIdentifier;
    }
    return nullptr;
  }

  const uint32_t format_version = reader->ReadUInt32();
  if (format_version != kSupportedKernelFormatVersion) {
    if (error != nullptr) {
      *error = kKernelInvalidBinaryFormatVersion;
    }
    return nullptr;
  }

  if (!IsValidSdkHash(reader->BufferAt(reader->offset()))) {
    if (error != nullptr) {
      *error = kKernelInvalidSdkHash;
    }
    return nullptr;
  }
  reader->set_offset(reader->offset() + kSdkHashSizeInBytes);

  std::unique_ptr<Program> program(new Program(reader->typed_data()));

  // Dill files can be concatenated (e.g. cat a.dill b.dill > c.dill). Find out
  // if this dill contains more than one program.
  int subprogram_count = 0;
  reader->set_offset(reader->size() - 4);
  while (reader->offset() > 0) {
    intptr_t size = reader->ReadUInt32();
    intptr_t start = reader->offset() - size;
    if (start < 0 || size <= 0) {
      if (error != nullptr) {
        *error = kKernelInvalidSizeIndicated;
      }
      return nullptr;
    }
    ++subprogram_count;
    if (subprogram_count > 1) break;
    reader->set_offset(start - 4);
  }
  program->single_program_ = subprogram_count == 1;

  // Read backwards at the end.
  program->library_count_ = reader->ReadFromIndexNoReset(
      reader->size_, LibraryCountFieldCountFromEnd, 1, 0);
  intptr_t count_from_first_library_offset =
      SourceTableFieldCountFromFirstLibraryOffset;
  program->source_table_offset_ = reader->ReadFromIndexNoReset(
      reader->size_,
      LibraryCountFieldCountFromEnd + 1 + program->library_count_ + 1 +
          count_from_first_library_offset,
      1, 0);
  program->constant_table_offset_ = reader->ReadUInt32();
  reader->ReadUInt32();  // offset for constant table index.
  program->name_table_offset_ = reader->ReadUInt32();
  program->metadata_payloads_offset_ = reader->ReadUInt32();
  program->metadata_mappings_offset_ = reader->ReadUInt32();
  program->string_table_offset_ = reader->ReadUInt32();
  // The below includes any 8-bit alignment; denotes the end of the previous
  // block.
  program->component_index_offset_ = reader->ReadUInt32();

  program->main_method_reference_ = NameIndex(reader->ReadUInt32() - 1);
  reader->ReadUInt32();  // Read and ignore NNBD compilation mode.

  return program;
}

std::unique_ptr<Program> Program::ReadFromFile(
    const char* script_uri,
    const char** error /* = nullptr */) {
  Thread* thread = Thread::Current();
  auto isolate_group = thread->isolate_group();
  if (script_uri == nullptr) {
    return nullptr;
  }
  if (!isolate_group->HasTagHandler()) {
    return nullptr;
  }
  std::unique_ptr<kernel::Program> kernel_program;

  const String& uri = String::Handle(String::New(script_uri));
  const Object& ret = Object::Handle(isolate_group->CallTagHandler(
      CODE_kKernelTag, Object::null_object(), uri));
  if (ret.IsExternalTypedData()) {
    const auto& typed_data = ExternalTypedData::Cast(ret);
    kernel_program = kernel::Program::ReadFromTypedData(typed_data);
    return kernel_program;
  } else if (error != nullptr) {
    Api::Scope api_scope(thread);
    CODE_Handle retval = Api::NewHandle(thread, ret.ptr());
    {
      TransitionVMToNative transition(thread);
      *error = CODE_GetError(retval);
    }
  }
  return kernel_program;
}

std::unique_ptr<Program> Program::ReadFromBuffer(const uint8_t* buffer,
                                                 intptr_t buffer_length,
                                                 const char** error) {
  // Whoever called this method (e.g. embedder) has to ensure the buffer stays
  // alive until the VM is done with the last usage (e.g. isolate shutdown).
  const auto& binary = ExternalTypedData::Handle(ExternalTypedData::New(
      kExternalTypedDataUint8ArrayCid, const_cast<uint8_t*>(buffer),
      buffer_length, Heap::kNew));
  kernel::Reader reader(binary);
  return kernel::Program::ReadFrom(&reader, error);
}

std::unique_ptr<Program> Program::ReadFromTypedData(
    const ExternalTypedData& typed_data,
    const char** error) {
  kernel::Reader reader(typed_data);
  return kernel::Program::ReadFrom(&reader, error);
}

}  // namespace kernel
}  // namespace dart
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)
