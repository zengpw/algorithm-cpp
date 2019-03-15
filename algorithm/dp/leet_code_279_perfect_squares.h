//
//  leet_code_279_perfect_squares.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_279_perfect_squares_h
#define dp_leet_code_279_perfect_squares_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/perfect-squares/
//  题意： 求一个整数 = 最少几个完全平方数之和
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

        // 从 1 开始求解
        for (int n = 0; n < dp.size(); ++n)
        {
            // 每次会更新 dp[n + i*i], 但是循环结束实际有效的更新只有 dp[n + 1], 其它都是（有用的）中间值
            for (int i = 1; n + i*i < dp.size(); ++i)
            {
                dp[n + i*i] = min(dp[n + i*i], dp[n] + 1);
            }
        }

        return dp[n];
    }
};

#endif // dp_leet_code_279_perfect_squares_h
