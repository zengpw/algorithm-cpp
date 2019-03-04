//
//  dpTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leetCodeUtil.h"

#include "algorithm/dp/leet_code_322_coin_change.h"

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
