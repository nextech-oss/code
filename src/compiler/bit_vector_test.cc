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

#include "src/bit_vector.h"
#include "platform/assert.h"
#include "src/unit_test.h"

namespace Code {

#define Z (thread->zone())

TEST_CASE(BitVector) {
  {
    BitVector* v = new BitVector(Z, 15);
    v->Add(1);
    EXPECT_EQ(true, v->Contains(1));
    EXPECT_EQ(false, v->Contains(0));
    {
      BitVector::Iterator iter(v);
      EXPECT_EQ(1, iter.Current());
      iter.Advance();
      EXPECT(iter.Done());
    }
    v->Add(0);
    v->Add(1);
    EXPECT_EQ(true, v->Contains(0));
    EXPECT_EQ(true, v->Contains(1));
    {
      BitVector::Iterator iter(v);
      EXPECT_EQ(0, iter.Current());
      iter.Advance();
      EXPECT_EQ(1, iter.Current());
      iter.Advance();
      EXPECT(iter.Done());
    }
  }

  {
    BitVector* v = new BitVector(Z, 128);
    v->Add(49);
    v->Add(62);
    v->Add(63);
    v->Add(65);
    EXPECT_EQ(true, v->Contains(49));
    EXPECT_EQ(true, v->Contains(62));
    EXPECT_EQ(true, v->Contains(63));
    EXPECT_EQ(true, v->Contains(65));
    EXPECT_EQ(false, v->Contains(64));
    BitVector::Iterator iter(v);
    EXPECT_EQ(49, iter.Current());
    iter.Advance();
    EXPECT_EQ(62, iter.Current());
    iter.Advance();
    EXPECT_EQ(63, iter.Current());
    iter.Advance();
    EXPECT_EQ(65, iter.Current());
    iter.Advance();
    EXPECT(iter.Done());
  }

  {
    BitVector* a = new BitVector(Z, 128);
    BitVector* b = new BitVector(Z, 128);
    BitVector* c = new BitVector(Z, 128);
    b->Add(0);
    b->Add(32);
    b->Add(64);
    a->AddAll(b);
    EXPECT_EQ(true, a->Contains(0));
    EXPECT_EQ(true, a->Contains(32));
    EXPECT_EQ(true, a->Contains(64));
    EXPECT_EQ(false, a->Contains(96));
    EXPECT_EQ(false, a->Contains(127));
    b->Add(96);
    b->Add(127);
    c->Add(127);
    a->KillAndAdd(c, b);
    EXPECT_EQ(true, a->Contains(0));
    EXPECT_EQ(true, a->Contains(32));
    EXPECT_EQ(true, a->Contains(64));
    EXPECT_EQ(true, a->Contains(96));
    EXPECT_EQ(false, a->Contains(127));
    a->Remove(0);
    a->Remove(32);
    a->Remove(64);
    a->Remove(96);
    EXPECT_EQ(false, a->Contains(0));
    EXPECT_EQ(false, a->Contains(32));
    EXPECT_EQ(false, a->Contains(64));
    EXPECT_EQ(false, a->Contains(96));
  }

  {
    BitVector* a = new BitVector(Z, 34);
    BitVector* b = new BitVector(Z, 34);
    a->SetAll();
    b->Add(0);
    b->Add(1);
    b->Add(31);
    b->Add(32);
    a->Intersect(b);
    EXPECT_EQ(true, a->Equals(*b));
  }

  {
    BitVector* a = new BitVector(Z, 2);
    BitVector* b = new BitVector(Z, 2);
    a->SetAll();
    a->Remove(0);
    a->Remove(1);
    EXPECT_EQ(true, a->Equals(*b));
  }

  {
    BitVector* a = new BitVector(Z, 128);
    BitVector* b = new BitVector(Z, 128);
    b->Add(0);
    b->Add(32);
    b->Add(64);
    a->Add(0);
    a->Add(64);
    b->RemoveAll(a);
    EXPECT_EQ(false, b->Contains(0));
    EXPECT_EQ(true, b->Contains(32));
    EXPECT_EQ(false, b->Contains(64));
  }
}

}  // namespace dart
