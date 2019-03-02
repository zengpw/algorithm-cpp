//
//  130_surrounded_regions.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/2/28.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef bfs_130_surrounded_regions_h
#define bfs_130_surrounded_regions_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/surrounded-regions/
//  题意： 如果 'O' 被 'X' 包围，则将其翻转成 'X'
//
class Solution
{
public:
    queue<pair<int, int>> nQueue;           // 存放标记为 'N' 的成员
public:
    void solve(vector<vector<char>>& board)
    {
        // clear
        queue<pair<int, int>> empty;
        swap(empty, nQueue);

        // 先找到四边上的 'O', 这些都是不被 'X' 包围的，标记为 'N'
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'O' &&
                    (i == 0 || i == board.size() - 1 ||
                     j == 0 || j == board[i].size() - 1))
                {
                    board[i][j] = 'N';
                    nQueue.push(make_pair(i, j));
                }
            }
        }

        // 遍历找到的 'O', 将每一个 'O' 都作为 bfs 算法的 起点，对外进行扩散
        // 一个无需翻转的 'O' 旁边的 'O' 必然是不需要翻转的，标记所有不翻转点为 'N', 直到没有新的不需要翻转的 'O' 被找到为止
        while (!nQueue.empty())
        {
            bfs(board, nQueue.front());             // 先进先出，实际上的扩散是按层级来的
            nQueue.pop();
        }

        // 再找到剩余的 'O', 即不在四边上，也没有被标记为 'N' 的，在图内部的 'O', 直接翻转成 'X'
        // 遍历整个图，将 'N' 变回 'O'
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
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
    void bfs(vector<vector<char>>& board, pair<int, int> item)
    {
        int i = item.first;
        int j = item.second;

        // 左
        if (isEqual(board, i, j - 1, 'O'))
        {
            board[i][j - 1] = 'N';
            nQueue.push(make_pair(i, j - 1));
        }
        // 上
        if (isEqual(board, i - 1, j, 'O'))
        {
            board[i - 1][j] = 'N';
            nQueue.push(make_pair(i - 1, j));
        }
        // 右
        if (isEqual(board, i, j + 1, 'O'))
        {
            board[i][j + 1] = 'N';
            nQueue.push(make_pair(i, j + 1));
        }
        // 下
        if (isEqual(board, i + 1, j, 'O'))
        {
            board[i + 1][j] = 'N';
            nQueue.push(make_pair(i + 1, j));
        }
    }

    bool isEqual(vector<vector<char>>& board, int i, int j, char value)
    {
        int maxX = board.size();
        int maxY = board[0].size();

        if (i < 0 || i >= maxX || j < 0 || j >= maxY)
            return false;

        if (board[i][j] == value)
            return true;
        else
            return false;
    }
};

#endif // bfs_130_surrounded_regions_h
