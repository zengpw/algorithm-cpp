//
//  leet_code_329_longest_increasing_path.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/11/1.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dfs_leet_code_329_longest_increasing_path_h
#define dfs_leet_code_329_longest_increasing_path_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//  题意： 求最长递增路径的长度，用 DFS 和 记忆化搜索 解决
//
class Solution329
{
private:
    vector<vector<int>> dp;                         // dp[x][y] = 从该点出发的最长递增路径的长度
    int maxDP;                                      // 所有 dp[x][y] 中的最大值
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;

        // 初始化 dp
        int maxX = matrix.size();
        int maxY = matrix[0].size();

        vector<int> model(maxY, 0);
        dp.resize(maxX, model);

        maxDP = 1;

        for (int i = 0; i < maxX; ++i)
        {
            for (int j = 0; j < maxY; ++j)
            {
                dfs(matrix, i, j);
            }
        }

        return maxDP;
    }

private:
    int dfs(vector<vector<int>> &matrix, int x, int y)
    {
        if (!isValidIndex(matrix, x, y))
            return 0;

        if (dp[x][y] == 0)
        {
            dp[x][y] = 1;

            if (isValidIndex(matrix, x - 1, y) && matrix[x][y] < matrix[x - 1][y])
            {
                int top = dfs(matrix, x - 1, y);
                dp[x][y] = max(dp[x][y], top + 1);
            }

            if (isValidIndex(matrix, x + 1, y) && matrix[x][y] < matrix[x + 1][y])
            {
                int bottom = dfs(matrix, x + 1, y);
                dp[x][y] = max(dp[x][y], bottom + 1);
            }

            if (isValidIndex(matrix, x, y - 1) && matrix[x][y] < matrix[x][y - 1])
            {
                int left = dfs(matrix, x, y - 1);
                dp[x][y] = max(dp[x][y], left + 1);
            }

            if (isValidIndex(matrix, x, y + 1) && matrix[x][y] < matrix[x][y + 1])
            {
                int right = dfs(matrix, x, y + 1);
                dp[x][y] = max(dp[x][y], right + 1);
            }
        }

        maxDP = max(dp[x][y], maxDP);

        return dp[x][y];
    }

    bool isValidIndex(vector<vector<int>> &matrix, int x, int y)
    {
        auto maxX = matrix.size() - 1;
        auto maxY = matrix[0].size() - 1;

        return !(x < 0 || y < 0 || x > maxX || y > maxY);
    }
};

#endif // dfs_leet_code_329_longest_increasing_path_h
