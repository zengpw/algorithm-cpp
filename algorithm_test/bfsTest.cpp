//
//  bfsTest.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/1.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leetCodeUtil.h"

#include "algorithm/bfs/leet_code_130_surrounded_regions.h"

TEST(bfsTest, p130)
{
    Solution130 solution;

    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    vector<vector<char>> boardFlipped = {{'X', 'X', 'X', 'X'},
                                         {'X', 'X', 'X', 'X'},
                                         {'X', 'X', 'X', 'X'},
                                         {'X', 'O', 'X', 'X'},
                                         {'X', 'O', 'X', 'X'}};

    solution.solve(board);

    std::string strBoard = stlUtil::vectorVector2String<char>(board);
    std::string strBoardFlipped = stlUtil::vectorVector2String<char>(boardFlipped);

    EXPECT_STREQ(strBoard.c_str(), strBoardFlipped.c_str());
}
