//
//  dfs_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/19.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "util.h"

#include "algorithm/leetcode/dfs/leet_code_200_number_of_islands.h"
#include "algorithm/leetcode/dfs/leet_code_207_course_schedule.h"
#include "algorithm/leetcode/dfs/leet_code_329_longest_increasing_path.h"

TEST(dfsTest, p200)
{
    Solution200 solution;

    vector<vector<char>> grids1 = {{'1', '1', '1', '1', '0'},
                                   {'1', '1', '0', '1', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '0', '0', '0'}};

    auto result1 = solution.numIslands(grids1);
    EXPECT_EQ(1, result1);

    vector<vector<char>> grids2 = {{'1', '1', '0', '0', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '1', '0', '0'},
                                   {'0', '0', '0', '1', '1'}};

    auto result2 = solution.numIslands(grids2);
    EXPECT_EQ(3, result2);
}

TEST(dfsTest, p207)
{
    Solution207 solution;

    vector<vector<int>> prerequisites1 = {{0, 1}};
    EXPECT_TRUE(solution.canFinish(prerequisites1.size(), prerequisites1));

    vector<vector<int>> prerequisites2 = {{0, 1},
                                          {1, 0}};
    EXPECT_FALSE(solution.canFinish(prerequisites2.size(), prerequisites2));

    vector<vector<int>> prerequisites3 = {{0, 1},
                                          {0, 2},
                                          {1, 2}};
    EXPECT_TRUE(solution.canFinish(prerequisites3.size(), prerequisites3));
}

TEST(dfsTest, p329)
{
    Solution329 solution;

    vector<vector<int>> nums1 = {{9, 9, 4},
                                 {6, 6, 8},
                                 {2, 1, 1}};

    auto result1 = solution.longestIncreasingPath(nums1);
    EXPECT_EQ(4, result1);

    vector<vector<int>> nums2 = {{3, 4, 5},
                                 {3, 2, 6},
                                 {2, 2, 1}};

    auto result2 = solution.longestIncreasingPath(nums2);
    EXPECT_EQ(4, result2);
}
