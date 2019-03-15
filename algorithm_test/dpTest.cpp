//
//  dpTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leetCodeUtil.h"

#include "algorithm/dp/leet_code_279_perfect_squares.h"
#include "algorithm/dp/leet_code_300_longest_increasing_subsequence.h"
#include "algorithm/dp/leet_code_322_coin_change.h"

TEST(dpTest, p279)
{
    Solution279 solution;

    int input1 = 12;
    int expectResult1 = 3;
    int result1 = solution.numSquares(input1);
    EXPECT_EQ(result1, expectResult1);

    int input2 = 13;
    int expectResult2 = 2;
    int result2 = solution.numSquares(input2);
    EXPECT_EQ(result2, expectResult2);
}

TEST(dpTest, p300)
{
    Solution300 solution;

    vector<int> nums1;
    int expectResult1 = 0;
    int result1 = solution.lengthOfLIS(nums1);
    EXPECT_EQ(result1, expectResult1);

    vector<int> nums2 = {0};
    int expectResult2 = 1;
    int result2 = solution.lengthOfLIS(nums2);
    EXPECT_EQ(result2, expectResult2);

    vector<int> nums3 = {10, 9, 2, 5, 3, 7, 101, 18};
    int expectResult3 = 4;
    int result3 = solution.lengthOfLIS(nums3);
    EXPECT_EQ(result3, expectResult3);
}

TEST(dpTest, p322)
{
    Solution322 solution;

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int expectResult1 = 3;
    int result1 = solution.coinChange(coins1, amount1);
    EXPECT_EQ(result1, expectResult1);

    vector<int> coins2 = {2};
    int amount2 = 3;
    int expectResult2 = -1;
    int result2 = solution.coinChange(coins2, amount2);
    EXPECT_EQ(result2, expectResult2);

    vector<int> coins3 = {186, 419, 83, 408};
    int amount3 = 6249;
    int expectResult3 = 20;
    int result3 = solution.coinChange(coins3, amount3);
    EXPECT_EQ(result3, expectResult3);
}
