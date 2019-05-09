//
//  leet_code_887_super_egg_drop.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/7.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_887_super_egg_drop_h
#define dp_leet_code_887_super_egg_drop_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/super-egg-drop/
//  题意： 用 k 个鸡蛋，测试在 n 层高的楼第几层鸡蛋会碎，求 最坏情况下 的 最少抛掷次数
//
class Solution887
{
public:
    int superEggDrop(int K, int N)
    {
        if (K <= 0 || N <= 0)
            return 0;

        // dp[K][S], dp[][] = 所能测试的最大层数
        // K = 鸡蛋规模, S = 抛掷次数，初始为 0, 上限为 N
        int dp[K + 1][N + 1];
        memset(dp, 0, sizeof(dp));

        for (int s = 1; s < N + 1; ++s)
        {
            // 计算 [1 -> K] 个鸡蛋时，抛 s 次能测试的层数
            for (int i = 1; i < K + 1; ++i)
            {
                // 当前能测试的最大层数 = 之前能测试的层数 + 没碎能测试的层数(1) + 碎后能测试的层数
                dp[i][s] = dp[i][s - 1] + 1 + dp[i - 1][s - 1];
            }

            if (dp[K][s] >= N)
                return s;
        }

        return N;
    }
};

#endif // dp_leet_code_887_super_egg_drop_h
