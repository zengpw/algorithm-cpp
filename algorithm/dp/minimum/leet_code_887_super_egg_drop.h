//
//  leet_code_887_super_egg_drop.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/7.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_minimum_leet_code_887_super_egg_drop_h
#define dp_minimum_leet_code_887_super_egg_drop_h

#include "util/int_util.h"
#include "util/leet_code_util.h"

using namespace std;

//
//  https://leetcode.com/problems/super-egg-drop/
//  题意： 用 k 个鸡蛋测试高度为 n 的楼，假如从第 f 层开始，抛下鸡蛋会碎，求测试出 f 需要的 最少抛掷次数
//
class Solution887
{
public:
    int superEggDrop(int K, int N)
    {
        if (K <= 0 || N <= 0)
            return 0;

        // K = 鸡蛋规模, S = 抛掷次数
        // dp[K][S] = K 个鸡蛋抛掷 S 次，所能测试的最大层数，初始为 0, 上限为 N
        int dp[K + 1][N + 1];
        memset(dp, 0, sizeof(dp));

        for (int steps = 1; steps < N + 1; ++steps)
        {
            for (int i = 1; i < K + 1; ++i)
            {
                // i 个鸡蛋抛掷 steps 次，能测试的 “最大” 层数 = 1 + 当前鸡蛋没碎能测试的层数 + 当前鸡蛋碎了能测试的层数
                dp[i][steps] = 1 + dp[i][steps - 1] + dp[i - 1][steps - 1];

                if (dp[i][steps] >= N)
                    return steps;
            }
        }
        
        return N;
    }
};

#endif // dp_minimum_leet_code_887_super_egg_drop_h
