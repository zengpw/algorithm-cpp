//
//  leet_code_279_perfect_squares.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_279_perfect_squares_h
#define dp_leet_code_279_perfect_squares_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/perfect-squares/
//  题意： 求一个整数 = 最少几个完全平方数之和，比如 5 = 1 + 4
//
class Solution279
{
public:
    int numSquares(int n)
	{
        if (n == 0)
            return 0;

        // 因为至多需要 n 个 1 相加，所以初始值为 n + 1, 方便判断
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        // 从 0 开始循环，才能从 dp[1] 开始求解
        for (int n = 0; n < dp.size(); ++n)
        {
            // 每次会更新 dp[n + i*i]
            // 但是只有 dp[n + 1] 一定是最优解，其它都是中间值（可能也是最优解）
            for (int i = 1; n + i*i < dp.size(); ++i)
            {
                // 递推公式 dp[n] = dp[?] + i*i
                dp[n + i*i] = min(dp[n + i*i], dp[n] + 1);
            }
        }

        return dp[n];
    }
};

#endif // dp_leet_code_279_perfect_squares_h
