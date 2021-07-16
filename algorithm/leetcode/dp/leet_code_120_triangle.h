//
//  leet_code_120_triangle.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_120_triangle_h
#define dp_leet_code_120_triangle_h

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/triangle/
//  题意： 求 三角形数组 顶点到底边 的最小路径和，数塔问题
//
class Solution120
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0)
                {
                    // 每行第一个点
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                }
                else if (j == i)
                {
                    // 每行最后一个点
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

#endif // dp_leet_code_120_triangle_h
