//
//  leet_code_322_coin_change.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/3.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_322_coin_change_h
#define dp_leet_code_322_coin_change_h

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/coin-change/
//  题意： 在金额固定的情况下，计算所需的硬币的最小数，也属于完全背包问题
//
class Solution322
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // n 和 i 之间的关系不是简单的 +1, 需要考虑另一个维度，即硬币的数值
        for (int n = 1; n < dp.size(); ++n)
        {
            for (int i = 0; i < coins.size(); ++i)
            {
                if (coins[i] <= n)
                    dp[n] = min(dp[n], dp[n - coins[i]] + 1);
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

#endif // dp_leet_code_322_coin_change_h
