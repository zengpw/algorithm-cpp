//
//  lcBasicTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/10.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/lc_basic/leet_code_1_two_sum.h"
#include "algorithm/lc_basic/leet_code_15_three_sum.h"

TEST(lcBasicTest, p1)
{
    Solution1 solution;

    vector<int> input1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(input1, target1);
    EXPECT_EQ(input1[result1[0]] + input1[result1[1]], 9);

    vector<int> input2 = {3, 3};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(input2, target2);
    EXPECT_EQ(input2[result2[0]] + input2[result2[1]], 6);

    vector<int> input3 = {3, 2, 4};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(input3, target3);
    EXPECT_EQ(result3[0] + result3[1], 3);      // [1] + [2]
}

TEST(lcBasicTest, p15)
{
    Solution15 solution;

    vector<int> input1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(input1);
    EXPECT_EQ(result1.size(), 2);
    EXPECT_EQ(result1[0][0] + result1[0][1] + result1[0][2], 0);
    EXPECT_EQ(result1[1][0] + result1[1][1] + result1[1][2], 0);

    vector<int> input2 = {0};
    vector<vector<int>> result2 = solution.threeSum(input2);
    EXPECT_EQ(result2.size(), 0);

    vector<int> input3 = {0, 0, 0};
    vector<vector<int>> result3 = solution.threeSum(input3);
    EXPECT_EQ(result3.size(), 1);
}
