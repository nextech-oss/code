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

#ifndef RUNTIME_VM_FINALIZABLE_DATA_H_
#define RUNTIME_VM_FINALIZABLE_DATA_H_

#include "include/CODE_api.h"
#include "platform/growable_array.h"
#include "src/globals.h"

namespace Code {

struct FinalizableData {
  void* data;
  void* peer;
  CODE_HandleFinalizer callback;
  CODE_HandleFinalizer successful_write_callback;
};

class MessageFinalizableData {
 public:
  MessageFinalizableData()
      : records_(0), get_position_(0), take_position_(0), external_size_(0) {}

  ~MessageFinalizableData() {
    for (intptr_t i = take_position_; i < records_.length(); i++) {
      records_[i].callback(nullptr, records_[i].peer);
    }
  }

  /// If [successful_write_callback] is provided, it's invoked when message
  /// was serialized successfully.
  /// [callback] is invoked when serialization failed.
  void Put(intptr_t external_size,
           void* data,
           void* peer,
           CODE_HandleFinalizer callback,
           CODE_HandleFinalizer successful_write_callback = nullptr) {
    FinalizableData finalizable_data;
    finalizable_data.data = data;
    finalizable_data.peer = peer;
    finalizable_data.callback = callback;
    finalizable_data.successful_write_callback = successful_write_callback;
    records_.Add(finalizable_data);
    external_size_ += external_size;
  }

  // Retrieve the next FinalizableData, but still run its finalizer when |this|
  // is destroyed.
  FinalizableData Get() {
    ASSERT(get_position_ < records_.length());
    return records_[get_position_++];
  }

  // Retrieve the next FinalizableData, and skip its finalizer when |this| is
  // destroyed.
  FinalizableData Take() {
    ASSERT(take_position_ < records_.length());
    return records_[take_position_++];
  }

  void SerializationSucceeded() {
    for (intptr_t i = 0; i < records_.length(); i++) {
      if (records_[i].successful_write_callback != nullptr) {
        records_[i].successful_write_callback(nullptr, records_[i].peer);
      }
    }
  }

  void DropFinalizers() {
    records_.Clear();
    get_position_ = 0;
    take_position_ = 0;
    external_size_ = 0;
  }

  intptr_t external_size() const { return external_size_; }

 private:
  MallocGrowableArray<FinalizableData> records_;
  intptr_t get_position_;
  intptr_t take_position_;
  intptr_t external_size_;

  DISALLOW_COPY_AND_ASSIGN(MessageFinalizableData);
};

}  // namespace dart

#endif  // RUNTIME_VM_FINALIZABLE_DATA_H_
