//
//  leet_code_200_number_of_islands.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/10/18.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dfs_leet_code_200_number_of_islands_h
#define dfs_leet_code_200_number_of_islands_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/number-of-islands/
//  题意： 单个或连续（上下左右相接）的 '1' 会形成一个岛屿，求岛屿数量
//
class Solution200
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int numberOfIslands = 0;

        if (grid.size() == 0)
            return 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    numberOfIslands++;
                    dfs(grid, make_pair(i, j));
                }
            }
        }

        return numberOfIslands;
    }

private:
    void dfs(vector<vector<char>> &grid, pair<int, int> item)
    {
        auto x = item.first;
        auto y = item.second;

        auto maxX = grid.size() - 1;
        auto maxY = grid[0].size() - 1;

        if (x < 0 || x > maxX || y < 0 || y > maxY)
            return;

        if (grid[x][y] == '1')
        {
            grid[x][y] = '0';

            // 处理上下左右
            dfs(grid, make_pair(x - 1, y));
            dfs(grid, make_pair(x + 1, y));
            dfs(grid, make_pair(x, y - 1));
            dfs(grid, make_pair(x, y + 1));
        }
    }
};

#endif // dfs_leet_code_200_number_of_islands_h
