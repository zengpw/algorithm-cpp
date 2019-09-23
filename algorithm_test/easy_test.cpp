//
//  easy_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/11/20.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/easy/bitwise.h"
#include "algorithm/easy/leet_code_1_two_sum.h"
#include "algorithm/easy/leet_code_15_three_sum.h"
#include "algorithm/easy/recurrence.h"
#include "algorithm/easy/recursion.h"

// test data for recursion, recurrence, iteration
const int fibonacci[30] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
                           55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
                           6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};

// test data for bitwise operation
const int twoNumberAppearsOnceArray[16] = {3, 5, 9, 0, 1, 7, 3, 9, 7, 1, 5, 2, 4, 6, 0, 4};
const int twoNumberAppearsOnceArrayResult[2] = {2, 6};

int twoNumberAppearsOnce2Array[13] = {3, 5, 9, 0, 1, 3, 5, 9, 0, 0, 5, 3, 9};

TEST(easyTest, findNumberAppearsOnce)
{
    auto result1 = findNumberAppearsOnce(twoNumberAppearsOnceArray, 16);
    EXPECT_EQ(result1.size(), 2);

    for (const auto& i : result1)
    {
        EXPECT_TRUE(existsInArray(twoNumberAppearsOnceArrayResult, 2, i));
    }
}

TEST(easyTest, findNumberAppearsOnce2)
{
    int result1 = findNumberAppearsOnce2(twoNumberAppearsOnce2Array, 13);
    EXPECT_EQ(result1, 1);
}

TEST(easyTest, fibonacciRS)
{
    int result1 = fibonacciRS(15);
    EXPECT_EQ(result1, 610);

    int result2 = fibonacciRS(25);
    EXPECT_EQ(result2, 75025);
}

TEST(easyTest, fibonacciRR)
{
    int result1 = fibonacciRR(15);
    EXPECT_EQ(result1, 610);

    int result2 = fibonacciRR(25);
    EXPECT_EQ(result2, 75025);
}

TEST(easyTest, p1)
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

TEST(easyTest, p15)
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
