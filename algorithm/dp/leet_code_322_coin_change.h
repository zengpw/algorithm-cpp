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
        // 记录问题的规模 dp[n], 其中 n = 需要找零的金额, dp[n] = 该金额对应的最优解
        // dp[n] 初始值 amount + 1, 用于是否存在最优解判断，小于此值即存在更好的解法
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // 对硬币从大到小排序，没有特殊的意义，只是执行顺序整齐一点
        sort(coins.begin(), coins.end(), greater<int>());

        // 规模从小到大，在当前规模下，寻找最优解
        for (int n = 1; n < dp.size(); ++n)
        {
            for (int i = 0; i < coins.size(); ++i)
            {
                // 对所有满足条件的硬币都进行计算，满足条件的硬币 -> 不大于规模 n 即可
                if (n >= coins[i])
                {
                    // 当前规模的最优解 = 某一已知规模的最优解 + 1个特殊面值的硬币
                    // 找到最小解法
                    dp[n] = min(dp[n - coins[i]] + 1, dp[n]);
                }
            }
        }

        return (dp[amount] == amount + 1)?-1:dp[amount];
    }
};

#endif // dp_leet_code_322_coin_change_h
