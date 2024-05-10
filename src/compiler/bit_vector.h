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

#ifndef RUNTIME_VM_BIT_VECTOR_H_
#define RUNTIME_VM_BIT_VECTOR_H_

#include "src/allocation.h"
#include "src/isolate.h"
#include "src/zone.h"

namespace Code {

// Bit vector implementation.
class BitVector : public ZoneAllocated {
 public:
  // Iterator for the elements of this BitVector.
  class Iterator : public ValueObject {
   public:
    explicit Iterator(BitVector* target)
        : target_(target),
          bit_index_(-1),
          word_index_(0),
          current_word_(target->data_[0]) {
      ASSERT(target->data_length_ > 0);
      Advance();
    }
    ~Iterator() {}

    bool Done() const { return word_index_ >= target_->data_length_; }
    void Advance();

    intptr_t Current() const {
      ASSERT(!Done());
      return bit_index_;
    }

   private:
    BitVector* target_;
    intptr_t bit_index_;
    intptr_t word_index_;
    uword current_word_;

    friend class BitVector;
  };

  BitVector(Zone* zone, intptr_t length)
      : length_(length),
        data_length_(SizeFor(length)),
        data_(zone->Alloc<uword>(data_length_)) {
    Clear();
  }

  void CopyFrom(const BitVector* other) {
    Clear();
    AddAll(other);
  }

  static intptr_t SizeFor(intptr_t length) {
    return 1 + ((length - 1) / kBitsPerWord);
  }

  void Add(intptr_t i) {
    ASSERT(i >= 0 && i < length());
    data_[i / kBitsPerWord] |= (static_cast<uword>(1) << (i % kBitsPerWord));
  }

  void Remove(intptr_t i) {
    ASSERT(i >= 0 && i < length());
    data_[i / kBitsPerWord] &= ~(static_cast<uword>(1) << (i % kBitsPerWord));
  }

  void Set(intptr_t i, bool value) { value ? Add(i) : Remove(i); }

  bool Equals(const BitVector& other) const;

  // Add all elements that are in the bitvector from.
  bool AddAll(const BitVector* from);

  // Remove all elements that are in the bitvector from.
  bool RemoveAll(const BitVector* from);

  // From the bitvector gen add those elements that are not in the
  // bitvector kill.
  bool KillAndAdd(BitVector* kill, BitVector* gen);

  void Intersect(const BitVector* other);

  bool IsEmpty() const;

  bool Contains(intptr_t i) const {
    ASSERT(i >= 0 && i < length());
    uword block = data_[i / kBitsPerWord];
    return (block & (static_cast<uword>(1) << (i % kBitsPerWord))) != 0;
  }

  bool SubsetOf(const BitVector& other) {
    ASSERT(length_ == other.length_);
    for (intptr_t i = 0; i < data_length_; ++i) {
      if ((data_[i] & other.data_[i]) != data_[i]) return false;
    }
    return true;
  }

  void Clear() {
    for (intptr_t i = 0; i < data_length_; i++) {
      data_[i] = 0;
    }
  }

  void SetAll() {
    for (intptr_t i = 0; i < data_length_; i++) {
      data_[i] = static_cast<uword>(-1);
    }
  }

  intptr_t length() const { return length_; }

  void Print() const;

 private:
  intptr_t length_;
  intptr_t data_length_;
  uword* data_;

  DISALLOW_COPY_AND_ASSIGN(BitVector);
};

}  // namespace dart

#endif  // RUNTIME_VM_BIT_VECTOR_H_
