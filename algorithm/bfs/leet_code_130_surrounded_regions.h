//
//  leet_code_130_surrounded_regions.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/2/28.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef bfs_leet_code_130_surrounded_regions_h
#define bfs_leet_code_130_surrounded_regions_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/surrounded-regions/
//  题意： 如果单个或连续 'O' 被 'X' 完全包围，则将其翻转成 'X'
//
class Solution130
{
private:
    queue<pair<int, int>> nQueue;               // 存放标记为 'N' 的成员
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        
        auto maxX = board.size() - 1;
        auto maxY = board[0].size() - 1;

        // 先找到四边上的 'O', 这些都是不被 'X' 包围的，标记为 'N'
        for (int x = 0; x <= maxX; ++x)
        {
            for (int y = 0; y <= maxY; ++y)
            {
                if (x != 0 && x != maxX && y != 0 && y != maxY)
                    continue;

                if (board[x][y] == 'O')
                {
                    board[x][y] = 'N';
                    nQueue.emplace(make_pair(x, y));
                }
            }
        }

        // 遍历找到的 'O', 将每一个 'O' 都作为 bfs 算法的 起点，对外进行扩散
        // 一个无需翻转的 'O' 旁边的 'O' 必然是不需要翻转的，标记所有不翻转点为 'N', 直到没有新的不需要翻转的 'O' 被找到为止
        while (!nQueue.empty())
        {
            bfs(board, nQueue.front());
            nQueue.pop();
        }

        // 再找到剩余的 'O', 即不在四边上，也没有被标记为 'N' 的，在图内部的 'O', 直接翻转成 'X'
        // 遍历整个图，将 'N' 变回 'O'
        for (int i = 0; i <= maxX; ++i)
        {
            for (int j = 0; j <= maxY; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'N')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void bfs(vector<vector<char>> &board, pair<int, int> item)
    {
        int x = item.first;
        int y = item.second;

        auto maxX = board.size() - 1;
        auto maxY = board[0].size() - 1;

        // 上
        if (x - 1 >= 0 && board[x - 1][y] == 'O')
        {
            board[x - 1][y] = 'N';
            nQueue.emplace(make_pair(x - 1, y));
        }

        // 下
        if (x + 1 <= maxX && board[x + 1][y] == 'O')
        {
            board[x + 1][y] = 'N';
            nQueue.emplace(make_pair(x + 1, y));
        }

        // 左
        if (y - 1 >= 0 && board[x][y - 1] == 'O')
        {
            board[x][y - 1] = 'N';
            nQueue.emplace(make_pair(x, y - 1));
        }

        // 右
        if (y + 1 <= maxY && board[x][y + 1] == 'O')
        {
            board[x][y + 1] = 'N';
            nQueue.emplace(make_pair(x, y + 1));
        }
    }
};

#endif // bfs_leet_code_130_surrounded_regions_h
