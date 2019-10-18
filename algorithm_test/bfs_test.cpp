//
//  bfs_test.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/1.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#include "gtest/gtest.h"

#include "algorithm/util/leet_code_util.h"

#include "algorithm/bfs/leet_code_127_word_ladder.h"
#include "algorithm/bfs/leet_code_130_surrounded_regions.h"
#include "algorithm/bfs/leet_code_200_number_of_islands.h"

TEST(bfsTest, p127)
{
    Solution127 solution;

    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result1 = solution.ladderLength(beginWord1, endWord1, wordList1);
    EXPECT_EQ(result1, 5);

    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};

    int result2 = solution.ladderLength(beginWord2, endWord2, wordList2);
    EXPECT_EQ(result2, 0);
}

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

TEST(bfsTest, p200)
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
