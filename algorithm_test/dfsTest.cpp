//
//  dfsTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/4/19.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leetCodeUtil.h"

#include "algorithm/dfs/leet_code_207_course_schedule.h"

TEST(dfsTest, p207)
{
    Solution207 solution;

    vector<pair<int, int>> prerequisites1 = {{0, 1}};
    EXPECT_TRUE(solution.canFinish(prerequisites1.size(), prerequisites1));

    vector<pair<int, int>> prerequisites2 = {{0, 1}, {1, 0}};
    EXPECT_FALSE(solution.canFinish(prerequisites2.size(), prerequisites2));

    vector<pair<int, int>> prerequisites3 = {{0, 1}, {0, 2}, {1, 2}};
    EXPECT_TRUE(solution.canFinish(prerequisites3.size(), prerequisites3));
}
