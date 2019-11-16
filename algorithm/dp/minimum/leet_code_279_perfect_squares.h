//
//  leet_code_279_perfect_squares.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/4.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_minimum_leet_code_279_perfect_squares_h
#define dp_minimum_leet_code_279_perfect_squares_h

#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/perfect-squares/
//  题意： 给定一个整数，求 最少 需要几个 完全平方数 相加能等于该数，比如 5 = 1 + 4
//
class Solution279
{
public:
    int numSquares(int n)
    {
        if (n == 0)
            return 0;

        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        // n 和 i 之间的关系不是 +1, 而是 一个完全平方数
        for (int n = 0; n < dp.size(); ++n)
        {
            for (int i = 1; i * i <= n; ++i)
            {
                dp[n] = min(dp[n], dp[n - i * i] + 1);
            }
        }

        return dp[n];
    }
};

#endif // dp_minimum_leet_code_279_perfect_squares_h
