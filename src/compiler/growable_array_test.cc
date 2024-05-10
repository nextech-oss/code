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

#include <utility>

#include "platform/assert.h"
#include "src/growable_array.h"
#include "src/symbols.h"
#include "src/unit_test.h"

namespace Code {

template <class GrowableArrayInt, class GrowableArrayInt64>
void TestGrowableArray() {
  GrowableArrayInt g;
  EXPECT_EQ(0, g.length());
  EXPECT(g.is_empty());
  g.Add(5);
  EXPECT_EQ(5, g[0]);
  EXPECT_EQ(1, g.length());
  EXPECT(!g.is_empty());
  g.Add(3);
  const GrowableArrayInt& temp = g;
  EXPECT_EQ(5, temp[0]);
  EXPECT_EQ(3, temp[1]);
  for (int i = 0; i < 10000; i++) {
    g.Add(i);
  }
  EXPECT_EQ(10002, g.length());
  EXPECT_EQ(10000 - 1, g.Last());

  GrowableArrayInt64 f(10);
  EXPECT_EQ(0, f.length());
  f.Add(-1LL);
  f.Add(15LL);
  EXPECT_EQ(2, f.length());
  for (int64_t l = 0; l < 100; l++) {
    f.Add(l);
  }
  EXPECT_EQ(102, f.length());
  EXPECT_EQ(100 - 1, f.Last());
  EXPECT_EQ(-1LL, f[0]);

  GrowableArrayInt h;
  EXPECT_EQ(0, h.length());
  h.Add(101);
  h.Add(102);
  h.Add(103);
  EXPECT_EQ(3, h.length());
  EXPECT_EQ(103, h.Last());
  h.RemoveLast();
  EXPECT_EQ(2, h.length());
  EXPECT_EQ(102, h.Last());
  h.RemoveLast();
  EXPECT_EQ(1, h.length());
  EXPECT_EQ(101, h.Last());
  h.RemoveLast();
  EXPECT_EQ(0, h.length());
  EXPECT(h.is_empty());
  h.Add(-8899);
  h.Add(7908);
  EXPECT(!h.is_empty());
  h.Clear();
  EXPECT(h.is_empty());
}

TEST_CASE(GrowableArray) {
  TestGrowableArray<GrowableArray<int>, GrowableArray<int64_t> >();
}

TEST_CASE(MallocGrowableArray) {
  TestGrowableArray<MallocGrowableArray<int>, MallocGrowableArray<int64_t> >();
}

static int greatestFirst(const int* a, const int* b) {
  if (*a > *b) {
    return -1;
  } else if (*a < *b) {
    return 1;
  } else {
    return 0;
  }
}

TEST_CASE(GrowableArraySort) {
  GrowableArray<int> g;
  g.Add(12);
  g.Add(4);
  g.Add(64);
  g.Add(8);
  g.Sort(greatestFirst);
  EXPECT_EQ(64, g[0]);
  EXPECT_EQ(4, g.Last());
}

ISOLATE_UNIT_TEST_CASE(GrowableHandlePtr) {
  Zone* zone = Thread::Current()->zone();
  GrowableHandlePtrArray<const String> test1(zone, 1);
  EXPECT_EQ(0, test1.length());
  test1.Add(Symbols::Int());
  EXPECT(test1[0].ptr() == Symbols::Int().ptr());
  EXPECT_EQ(1, test1.length());

  ZoneGrowableHandlePtrArray<const String>* test2 =
      new ZoneGrowableHandlePtrArray<const String>(zone, 1);
  test2->Add(Symbols::GetterPrefix());
  EXPECT((*test2)[0].ptr() == Symbols::GetterPrefix().ptr());
  EXPECT_EQ(1, test2->length());
}

TEST_CASE(GrowableArrayMoveCtor) {
  GrowableArray<int> a;
  a.Add(4);
  a.Add(5);
  int* a_data = a.data();

  GrowableArray<int> b(std::move(a));

  EXPECT_EQ(0, a.length());
  EXPECT_EQ((int*)nullptr, a.data());
  EXPECT_EQ(2, b.length());
  EXPECT_EQ(a_data, b.data());
}

TEST_CASE(GrowableArrayMoveAssign) {
  GrowableArray<int> a, b;
  a.Add(1);
  a.Add(2);
  a.Add(3);
  b.Add(7);
  int* a_data = a.data();
  int* b_data = b.data();

  a = std::move(b);

  EXPECT_EQ(1, a.length());
  EXPECT_EQ(b_data, a.data());
  EXPECT_EQ(3, b.length());
  EXPECT_EQ(a_data, b.data());
}

}  // namespace dart
