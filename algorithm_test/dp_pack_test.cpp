//
//  dp_pack_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leet_code_util.h"

#include "algorithm/dp/pack/leet_code_120_triangle.h"
#include "algorithm/dp/pack/leet_code_416_partition_equal_subset_sum.h"

TEST(dpPackTest, p120)
{
    Solution120 solution;

    vector<vector<int>> triangle1 = {{2},
                                     {3, 4},
                                     {6, 5, 7},
                                     {4, 1, 8, 3}};

    int result1 = solution.minimumTotal(triangle1);
    EXPECT_EQ(result1, 11);
}

TEST(dpPackTest, p416)
{
    Solution416 solution;

    vector<int> input1 = {1, 5, 11, 5};
    bool result1 = solution.canPartition(input1);
    EXPECT_TRUE(result1);

    vector<int> input2 = {1, 2, 3, 5};
    bool result2 = solution.canPartition(input2);
    EXPECT_FALSE(result2);

    vector<int> input3 = {1, 2, 5};
    bool result3 = solution.canPartition(input3);
    EXPECT_FALSE(result3);
}
