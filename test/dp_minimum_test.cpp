//
//  dp_minimum_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/11/6.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "util.h"

#include "algorithm/leetcode/dp/leet_code_279_perfect_squares.h"
#include "algorithm/leetcode/dp/leet_code_322_coin_change.h"
#include "algorithm/leetcode/dp/leet_code_887_super_egg_drop.h"

TEST(dpMinimumTest, p279)
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

TEST(dpMinimumTest, p322)
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

TEST(dpMinimumTest, p887)
{
    Solution887 solution;

    int result = solution.superEggDrop(2, 100);
    EXPECT_EQ(result, 14);
}
