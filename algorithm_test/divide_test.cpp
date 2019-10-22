//
//  divide_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/18.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leet_code_util.h"

#include "algorithm/divide/leet_code_39_combination_sum.h"
#include "algorithm/divide/leet_code_46_permutations.h"
#include "algorithm/divide/leet_code_47_permutations_ii.h"
#include "algorithm/divide/leet_code_77_combinations.h"

TEST(divideTest, p39)
{
    Solution39 solution;

    // case 1
    int target1 = 7;
    vector<int> input1 = {2, 3, 6, 7};
    vector<vector<int>> output1 = {{7},
                                   {2, 2, 3}};
    vector<string> outputVec1;
    stlUtil::vectorVector2StringVector(output1, outputVec1);

    auto result1 = solution.combinationSum(input1, target1);

    // convert result format
    vector<string> resultVec1;
    stlUtil::vectorVector2StringVector(result1, resultVec1);

    unordered_set<string> resultSet1;
    copy(resultVec1.begin(), resultVec1.end(), inserter(resultSet1, resultSet1.end()));

    // check results
    for (auto &v : outputVec1)
    {
        if (resultSet1.count(v) == 0)
        {
            FAIL();
        }
    }

    // case 2
    int target2 = 8;
    vector<int> input2 = {2, 3, 5};
    vector<vector<int>> output2 = {{2, 2, 2, 2},
                                   {2, 3, 3},
                                   {3, 5}};
    vector<string> outputVec2;
    stlUtil::vectorVector2StringVector(output2, outputVec2);

    auto result2 = solution.combinationSum(input2, target2);

    // convert result format
    vector<string> resultVec2;
    stlUtil::vectorVector2StringVector(result2, resultVec2);

    unordered_set<string> resultSet2;
    copy(resultVec2.begin(), resultVec2.end(), inserter(resultSet2, resultSet2.end()));

    // check results
    for (auto &v : outputVec2)
    {
        if (resultSet2.count(v) == 0)
        {
            FAIL();
        }
    }
}

TEST(divideTest, p46)
{
    Solution46 solution;

    vector<int> input1 = {1, 2, 3};

    vector<vector<int>> output1 = {{1, 2, 3},
                                   {1, 3, 2},
                                   {2, 1, 3},
                                   {2, 3, 1},
                                   {3, 1, 2},
                                   {3, 2, 1}};

    vector<string> outputVec1;
    stlUtil::vectorVector2StringVector(output1, outputVec1);

    auto result1 = solution.permute(input1);

    // convert result format
    vector<string> resultVec1;
    stlUtil::vectorVector2StringVector(result1, resultVec1);

    unordered_set<string> resultSet1;
    copy(resultVec1.begin(), resultVec1.end(), inserter(resultSet1, resultSet1.end()));

    // check results
    for (auto &v : outputVec1)
    {
        if (resultSet1.count(v) == 0)
        {
            FAIL();
        }
    }
}

TEST(divideTest, p47)
{
    Solution47 solution;

    vector<int> input1 = {1, 1, 2};

    vector<vector<int>> output1 = {{1, 1, 2},
                                   {1, 2, 1},
                                   {2, 1, 1}};

    vector<string> outputVec1;
    stlUtil::vectorVector2StringVector(output1, outputVec1);

    auto result1 = solution.permuteUnique(input1);

    // convert result format
    vector<string> resultVec1;
    stlUtil::vectorVector2StringVector(result1, resultVec1);

    unordered_set<string> resultSet1;
    copy(resultVec1.begin(), resultVec1.end(), inserter(resultSet1, resultSet1.end()));

    // check results
    for (auto &v : outputVec1)
    {
        if (resultSet1.count(v) == 0)
        {
            FAIL();
        }
    }
}

TEST(divideTest, p77)
{
    Solution77 solution;

    vector<vector<int>> output1 = {{2, 4},
                                   {3, 4},
                                   {2, 3},
                                   {1, 2},
                                   {1, 3},
                                   {1, 4}};

    vector<string> outputVec1;
    stlUtil::vectorVector2StringVector(output1, outputVec1);

    auto result1 = solution.combine(4, 2);

    // convert result format
    vector<string> resultVec1;
    stlUtil::vectorVector2StringVector(result1, resultVec1);

    unordered_set<string> resultSet1;
    copy(resultVec1.begin(), resultVec1.end(), inserter(resultSet1, resultSet1.end()));

    // check results
    for (auto &v : outputVec1)
    {
        if (resultSet1.count(v) == 0)
        {
            FAIL();
        }
    }
}
