//
//  leet_code_120_triangle.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/11.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_120_triangle_h
#define dp_leet_code_120_triangle_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/triangle/
//  题意： 求最小路径和，数塔问题
//
class Solution120
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        // 正三角形 -> 第 i 行元素总数 = i + 1, (i 从 0 开始)

        // 正常思路是 从上往下 的 动态规划 解法
        // 这里采用 自底向上 的 非动态规划 解法
        vector<int> result(triangle[triangle.size() - 1]);

        // 自底向上
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            // 对该层采用冒泡法，排除掉最后一个元素
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                // 想象以 [i, j] 为顶点的三角形，将 较小的顶点和 更新到该点，这样每层会丢弃最后一个元素
                result[j] = triangle[i][j] + min(result[j], result[j + 1]);
            }
        }

        return result[0];
    }
};

#endif // dp_leet_code_120_triangle_h
