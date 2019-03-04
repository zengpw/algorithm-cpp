//
//  leet_code_322_coin_change.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/3.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_322_coin_change_h
#define dp_leet_code_322_coin_change_h

#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/coin-change/
//  题意： 在金额固定的情况下，计算所需的硬币的最小数
//
class Solution322
{
public:
    int coinChange(vector<int>& coins, int amount)
	{
        // 记录问题的规模 dp[n], 其中 n = 需要找零的金额, dp[n] = 该金额对应的最优解，初始值为最大 amount + 1
        // 第 2 个 amount + 1 用于是否存在最优解判断
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // 对硬币从大到小排序，没有特殊的意义，只是执行顺序整齐一点
        sort(coins.begin(), coins.end(), greater<int>());

        // 规模从小到大，在当前规模下，寻找最优解
        for (int n = 1; n < dp.size(); ++n)
        {
            // 当前规模的最优解 = 某一已知规模的最优解 + (0-n)个硬币
            for (int i = 0; i < coins.size(); ++i)
            {
                // 选一个不大于当前规模的硬币，计算它的最优解
                if (n >= coins[i])
                {
                    // dp[n - coins[i]] + 1 = 某一已知规模的最优解 + 这枚硬币
                    dp[n] = min(dp[n - coins[i]] + 1, dp[n]);
                }
            }
        }

        return (dp[amount] == amount + 1)?-1:dp[amount];
    }
};

#endif // dp_leet_code_322_coin_change_h
