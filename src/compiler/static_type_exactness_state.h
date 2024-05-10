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

#ifndef RUNTIME_VM_STATIC_TYPE_EXACTNESS_STATE_H_
#define RUNTIME_VM_STATIC_TYPE_EXACTNESS_STATE_H_

#include "platform/allocation.h"
#include "platform/utils.h"

// This header defines the list of VM implementation classes and their ids.
//
// Note: we assume that all builds of Dart VM use exactly the same class ids
// for these classes.

namespace Code {

class Instance;
class Type;

// Representation of a state of runtime tracking of static type exactness for
// a particular location in the program (e.g. exactness of type annotation
// on a field).
//
// Given the static type G<T0, ..., Tn> we say that it is exact iff any
// values that can be observed at this location has runtime type T such that
// type arguments of T at G are exactly <T0, ..., Tn>.
//
// Currently we only support tracking for locations that are also known
// to be monomorphic with respect to the actual class of the values it contains.
//
// Important: locations should never switch from tracked (kIsTriviallyExact,
// kHasExactSuperType, kHasExactSuperClass, kNotExact) to not tracked
// (kNotTracking) or the other way around because that would affect unoptimized
// graphs generated by graph builder and skew deopt ids.
class StaticTypeExactnessState final {
 public:
  // Values stored in the location with static type G<T0, ..., Tn> are all
  // instances of C<T0, ..., Tn> and C<U0, ..., Un> at G has type parameters
  // <U0, ..., Un>.
  //
  // For trivially exact types we can simply compare type argument
  // vectors as pointers to check exactness. That's why we represent
  // trivially exact locations as offset in words to the type arguments of
  // class C. All other states are represented as non-positive values.
  //
  // Note: we are ignoring the type argument vector sharing optimization for
  // now.
  static inline StaticTypeExactnessState TriviallyExact(
      intptr_t type_arguments_offset_in_bytes) {
    ASSERT((type_arguments_offset_in_bytes > 0) &&
           Utils::IsInt(8, type_arguments_offset_in_bytes));
    return StaticTypeExactnessState(type_arguments_offset_in_bytes);
  }

  static inline bool CanRepresentAsTriviallyExact(
      intptr_t type_arguments_offset_in_bytes) {
    return Utils::IsInt(8, type_arguments_offset_in_bytes);
  }

  // Values stored in the location with static type G<T0, ..., Tn> are all
  // instances of class C<...> and C<U0, ..., Un> at G has type
  // parameters <T0, ..., Tn> for any <U0, ..., Un> - that is C<...> has a
  // supertype G<T0, ..., Tn>.
  //
  // For such locations we can simply check if the value stored
  // is an instance of an expected class and we don't have to look at
  // type arguments carried by the instance.
  //
  // We distinguish situations where we know that G is a superclass of C from
  // situations where G might be superinterface of C - because in the first
  // type arguments of G give us constant prefix of type arguments of C.
  static inline StaticTypeExactnessState HasExactSuperType() {
    return StaticTypeExactnessState(kHasExactSuperType);
  }

  static inline StaticTypeExactnessState HasExactSuperClass() {
    return StaticTypeExactnessState(kHasExactSuperClass);
  }

  // Values stored in the location don't fall under either kIsTriviallyExact
  // or kHasExactSuperType categories.
  //
  // Note: that does not imply that static type annotation is not exact
  // according to a broader definition, e.g. location might simply be
  // polymorphic and store instances of multiple different types.
  // However for simplicity we don't track such cases yet.
  static inline StaticTypeExactnessState NotExact() {
    return StaticTypeExactnessState(kNotExact);
  }

  // The location does not track exactness of its static type at runtime.
  static inline StaticTypeExactnessState NotTracking() {
    return StaticTypeExactnessState(kNotTracking);
  }

  static inline StaticTypeExactnessState Uninitialized() {
    return StaticTypeExactnessState(kUninitialized);
  }

  static StaticTypeExactnessState Compute(const Type& static_type,
                                          const Instance& value,
                                          bool print_trace = false);

  bool IsTracking() const { return value_ != kNotTracking; }
  bool IsUninitialized() const { return value_ == kUninitialized; }
  bool IsHasExactSuperClass() const { return value_ == kHasExactSuperClass; }
  bool IsHasExactSuperType() const { return value_ == kHasExactSuperType; }
  bool IsTriviallyExact() const { return value_ > kUninitialized; }
  bool NeedsFieldGuard() const { return value_ >= kUninitialized; }
  bool IsExactOrUninitialized() const { return value_ > kNotExact; }
  bool IsExact() const {
    return IsTriviallyExact() || IsHasExactSuperType() ||
           IsHasExactSuperClass();
  }

  const char* ToCString() const;

  StaticTypeExactnessState CollapseSuperTypeExactness() const {
    return IsHasExactSuperClass() ? HasExactSuperType() : *this;
  }

  static inline StaticTypeExactnessState Decode(int8_t value) {
    return StaticTypeExactnessState(value);
  }

  int8_t Encode() const { return value_; }
  int8_t GetTypeArgumentsOffsetInWords() const {
    ASSERT(IsTriviallyExact());
    return value_;
  }

  static constexpr int8_t kUninitialized = 0;

 private:
  static constexpr int8_t kNotTracking = -4;
  static constexpr int8_t kNotExact = -3;
  static constexpr int8_t kHasExactSuperType = -2;
  static constexpr int8_t kHasExactSuperClass = -1;

  explicit StaticTypeExactnessState(int8_t value) : value_(value) {}

  int8_t value_;

  DISALLOW_ALLOCATION();
};

}  // namespace dart

#endif  // RUNTIME_VM_STATIC_TYPE_EXACTNESS_STATE_H_
