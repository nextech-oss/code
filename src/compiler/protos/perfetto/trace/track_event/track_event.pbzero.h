// Copyright (c) 2023, the Dart project authors. Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

// IMPORTANT: This file should only ever be modified by modifying the
// corresponding .proto file and then running
// `dart runtime/src/protos/tools/compile_perfetto_protos.dart` from the SDK root
// directory.
// Autogenerated by the ProtoZero compiler plugin. DO NOT EDIT.

#ifndef PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_EVENT_PROTO_H_
#define PERFETTO_PROTOS_PROTOS_PERFETTO_TRACE_TRACK_EVENT_TRACK_EVENT_PROTO_H_

#include <stddef.h>
#include <stdint.h>

#include "perfetto/protozero/field_writer.h"
#include "perfetto/protozero/message.h"
#include "perfetto/protozero/packed_repeated_fields.h"
#include "perfetto/protozero/proto_decoder.h"
#include "perfetto/protozero/proto_utils.h"

namespace perfetto {
namespace protos {
namespace pbzero {

class DebugAnnotation;
namespace perfetto_pbzero_enum_TrackEvent {
enum Type : int32_t;
}  // namespace perfetto_pbzero_enum_TrackEvent
using TrackEvent_Type = perfetto_pbzero_enum_TrackEvent::Type;

namespace perfetto_pbzero_enum_TrackEvent {
enum Type : int32_t {
  TYPE_SLICE_BEGIN = 1,
  TYPE_SLICE_END = 2,
  TYPE_INSTANT = 3,
};
}  // namespace perfetto_pbzero_enum_TrackEvent
using TrackEvent_Type = perfetto_pbzero_enum_TrackEvent::Type;

constexpr TrackEvent_Type TrackEvent_Type_MIN =
    TrackEvent_Type::TYPE_SLICE_BEGIN;
constexpr TrackEvent_Type TrackEvent_Type_MAX = TrackEvent_Type::TYPE_INSTANT;

PERFETTO_PROTOZERO_CONSTEXPR14_OR_INLINE
const char* TrackEvent_Type_Name(
    ::perfetto::protos::pbzero::TrackEvent_Type value) {
  switch (value) {
    case ::perfetto::protos::pbzero::TrackEvent_Type::TYPE_SLICE_BEGIN:
      return "TYPE_SLICE_BEGIN";

    case ::perfetto::protos::pbzero::TrackEvent_Type::TYPE_SLICE_END:
      return "TYPE_SLICE_END";

    case ::perfetto::protos::pbzero::TrackEvent_Type::TYPE_INSTANT:
      return "TYPE_INSTANT";
  }
  return "PBZERO_UNKNOWN_ENUM_VALUE";
}

class TrackEvent_Decoder : public ::protozero::TypedProtoDecoder<
                               /*MAX_FIELD_ID=*/48,
                               /*HAS_NONPACKED_REPEATED_FIELDS=*/true> {
 public:
  TrackEvent_Decoder(const uint8_t* data, size_t len)
      : TypedProtoDecoder(data, len) {}
  explicit TrackEvent_Decoder(const std::string& raw)
      : TypedProtoDecoder(reinterpret_cast<const uint8_t*>(raw.data()),
                          raw.size()) {}
  explicit TrackEvent_Decoder(const ::protozero::ConstBytes& raw)
      : TypedProtoDecoder(raw.data, raw.size) {}
  bool has_categories() const { return at<22>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstChars> categories()
      const {
    return GetRepeated<::protozero::ConstChars>(22);
  }
  bool has_name() const { return at<23>().valid(); }
  ::protozero::ConstChars name() const { return at<23>().as_string(); }
  bool has_type() const { return at<9>().valid(); }
  int32_t type() const { return at<9>().as_int32(); }
  bool has_track_uuid() const { return at<11>().valid(); }
  uint64_t track_uuid() const { return at<11>().as_uint64(); }
  bool has_flow_ids() const { return at<47>().valid(); }
  ::protozero::RepeatedFieldIterator<uint64_t> flow_ids() const {
    return GetRepeated<uint64_t>(47);
  }
  bool has_terminating_flow_ids() const { return at<48>().valid(); }
  ::protozero::RepeatedFieldIterator<uint64_t> terminating_flow_ids() const {
    return GetRepeated<uint64_t>(48);
  }
  bool has_debug_annotations() const { return at<4>().valid(); }
  ::protozero::RepeatedFieldIterator<::protozero::ConstBytes>
  debug_annotations() const {
    return GetRepeated<::protozero::ConstBytes>(4);
  }
};

class TrackEvent : public ::protozero::Message {
 public:
  using Decoder = TrackEvent_Decoder;
  enum : int32_t {
    kCategoriesFieldNumber = 22,
    kNameFieldNumber = 23,
    kTypeFieldNumber = 9,
    kTrackUuidFieldNumber = 11,
    kFlowIdsFieldNumber = 47,
    kTerminatingFlowIdsFieldNumber = 48,
    kDebugAnnotationsFieldNumber = 4,
  };
  static constexpr const char* GetName() {
    return ".perfetto.protos.TrackEvent";
  }

  using Type = ::perfetto::protos::pbzero::TrackEvent_Type;
  static inline const char* Type_Name(Type value) {
    return ::perfetto::protos::pbzero::TrackEvent_Type_Name(value);
  }
  static const Type TYPE_SLICE_BEGIN = Type::TYPE_SLICE_BEGIN;
  static const Type TYPE_SLICE_END = Type::TYPE_SLICE_END;
  static const Type TYPE_INSTANT = Type::TYPE_INSTANT;

  using FieldMetadata_Categories = ::protozero::proto_utils::FieldMetadata<
      22,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Categories kCategories() { return {}; }
  void add_categories(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Categories::kFieldId, data, size);
  }
  void add_categories(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Categories::kFieldId, chars.data, chars.size);
  }
  void add_categories(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Categories::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kString>::Append(*this,
                                                                    field_id,
                                                                    value);
  }

  using FieldMetadata_Name = ::protozero::proto_utils::FieldMetadata<
      23,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kString,
      std::string,
      TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Name kName() { return {}; }
  void set_name(const char* data, size_t size) {
    AppendBytes(FieldMetadata_Name::kFieldId, data, size);
  }
  void set_name(::protozero::ConstChars chars) {
    AppendBytes(FieldMetadata_Name::kFieldId, chars.data, chars.size);
  }
  void set_name(std::string value) {
    static constexpr uint32_t field_id = FieldMetadata_Name::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kString>::Append(*this,
                                                                    field_id,
                                                                    value);
  }

  using FieldMetadata_Type = ::protozero::proto_utils::FieldMetadata<
      9,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kEnum,
      ::perfetto::protos::pbzero::TrackEvent_Type,
      TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_Type kType() { return {}; }
  void set_type(::perfetto::protos::pbzero::TrackEvent_Type value) {
    static constexpr uint32_t field_id = FieldMetadata_Type::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kEnum>::Append(*this,
                                                                  field_id,
                                                                  value);
  }

  using FieldMetadata_TrackUuid = ::protozero::proto_utils::FieldMetadata<
      11,
      ::protozero::proto_utils::RepetitionType::kNotRepeated,
      ::protozero::proto_utils::ProtoSchemaType::kUint64,
      uint64_t,
      TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TrackUuid kTrackUuid() { return {}; }
  void set_track_uuid(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_TrackUuid::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kUint64>::Append(*this,
                                                                    field_id,
                                                                    value);
  }

  using FieldMetadata_FlowIds = ::protozero::proto_utils::FieldMetadata<
      47,
      ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
      ::protozero::proto_utils::ProtoSchemaType::kFixed64,
      uint64_t,
      TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_FlowIds kFlowIds() { return {}; }
  void add_flow_ids(uint64_t value) {
    static constexpr uint32_t field_id = FieldMetadata_FlowIds::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kFixed64>::Append(*this,
                                                                     field_id,
                                                                     value);
  }

  using FieldMetadata_TerminatingFlowIds =
      ::protozero::proto_utils::FieldMetadata<
          48,
          ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
          ::protozero::proto_utils::ProtoSchemaType::kFixed64,
          uint64_t,
          TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_TerminatingFlowIds kTerminatingFlowIds() {
    return {};
  }
  void add_terminating_flow_ids(uint64_t value) {
    static constexpr uint32_t field_id =
        FieldMetadata_TerminatingFlowIds::kFieldId;
    // Call the appropriate protozero::Message::Append(field_id, ...)
    // method based on the type of the field.
    ::protozero::internal::FieldWriter<
        ::protozero::proto_utils::ProtoSchemaType::kFixed64>::Append(*this,
                                                                     field_id,
                                                                     value);
  }

  using FieldMetadata_DebugAnnotations =
      ::protozero::proto_utils::FieldMetadata<
          4,
          ::protozero::proto_utils::RepetitionType::kRepeatedNotPacked,
          ::protozero::proto_utils::ProtoSchemaType::kMessage,
          DebugAnnotation,
          TrackEvent>;

  // Ceci n'est pas une pipe.
  // This is actually a variable of FieldMetadataHelper<FieldMetadata<...>>
  // type (and users are expected to use it as such, hence kCamelCase name).
  // It is declared as a function to keep protozero bindings header-only as
  // inline constexpr variables are not available until C++17 (while inline
  // functions are).
  // TODO(altimin): Use inline variable instead after adopting C++17.
  static constexpr FieldMetadata_DebugAnnotations kDebugAnnotations() {
    return {};
  }
  template <typename T = DebugAnnotation>
  T* add_debug_annotations() {
    return BeginNestedMessage<T>(4);
  }
};

}  // namespace pbzero
}  // namespace protos
}  // namespace perfetto
#endif  // Include guard.
