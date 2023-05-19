#include <gtest/gtest.h>
#include "codility.h"

TEST(CodilityTest, BinaryGapTest) {
  EXPECT_EQ(codility::binary_gap(9), 2);
  EXPECT_EQ(codility::binary_gap(529), 4);
  EXPECT_EQ(codility::binary_gap(20), 1);
  
}

TEST(CodilityTest, FrogJumpTest) {
  EXPECT_EQ(codility::frog_jump(10, 85, 30), 3);
  EXPECT_EQ(codility::frog_jump(1, 5, 2), 2);
  EXPECT_EQ(codility::frog_jump(1, 1, 1), 0);

}

TEST(CodilityTest, SliceSumTest) {
  std::vector<int> A1 {3, 2, -6, 4, 0};
  EXPECT_EQ(codility::slice_sum(A1), 5);
  
  std::vector<int> A2 {-1, -2, -3, -4, -5};
  EXPECT_EQ(codility::slice_sum(A2), 0);
  
  std::vector<int> A3 {1, 2, 3, 4, 5};
  EXPECT_EQ(codility::slice_sum(A3), 14);

}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
