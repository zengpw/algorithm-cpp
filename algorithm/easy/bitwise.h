//
//  bitwise.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/3/22.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef easy_bitwise_h
#define easy_bitwise_h

#include "util/int_util.h"

using namespace std;

// 一个整型数组里除了 2 个数字之外，其他的数字都出现了 2 次，请写程序找出这 2 个只出现 1 次的数字
// 题解：最简单的异或题型
vector<int> findNumberAppearsOnce(const int array[], int length)
{
    // 计算这 2 个数的异或结果
    int xorResult = 0;
    for (int i = 0; i < length; ++i)
    {
        xorResult ^= array[i];
    }

    // 随便找到一个结果为 1 的位，目的是根据此位，将这个数组分成 2 个
    // 此位为 1, 意味着 只出现 1 次的数字 在这里为 1
    int xorPosition = 0;
    while ((xorResult ^ 1) != 0)
    {
        xorResult = xorResult >> 1;
        xorPosition++;
    }
    
    // 在实际操作中，可以不声明额外的数组，直接根据分组计算即可
    int a = 0;
    int b = 0;
    for (int i = 0; i < length; ++i)
    {
        if ((array[i] >> xorPosition) == 1)
        {
            a ^= array[i];
        }
        else
        {
            b ^= array[i];
        }
    }

    // 返回结果集
    vector<int> result = {a, b};
    return result;
}

// 一个整型数组里除了 1 个数字之外，其他的数字都出现了 3 次，请写程序找出这 1 个只出现 1 次的数字
// 题解： 简单异或无法解决，从二进制位、位操作方面去考虑
//
//      如果数组中的元素都是三个三个出现的，那么从二进制表示的角度，每个位上的 1 加起来，应该可以 整除3
//      如果无法整除，则说明多出来的那个数字此位为 1, 否则那位数字此位为 0
//
int findNumberAppearsOnce2(int array[], int length)
{
    int result[32] = {0};

    // 十进制转二进制： 使用辗转相除法（除2求余，余数为所求二进制对应位的值，商则用于计算下一位的值）
    // 在转换的同时，直接进行加法
    // 0 - 31 代表 int32 的 4 个字节
    for (int i = 0; i < 32; ++i)
    {
        // 每个数字 对应的位 都要相加
        for (int j = 0; j < length; ++j)
        {
            result[i] += array[j]%2;
            array[j] >>= 1;
        }
        // 然后进行 %3
        result[i] %= 3;
    }

    // result[] = 只出现 1 次的数字，将这个数组变回十进制
    // 二进制转十进制： 如果第 k 位为 1, 则乘以 2 的 k 次方，最后相加即可
    int rtn = 0;
    for (int k = 0; k < 32; ++k)
    {
        if (result[k] == 1)
            rtn += (1 << k);
    }

    return rtn;
}

// 一个全是数字的大数组，除了其中 1 个数字出现 2 次外，其余的数字都出现了 3 次
// 题解： 这是 findNumberAppearsOnce2 的变形
//
//      如果这个数字出现了 2 次，则需要在 %3 取余的基础上，再 /2 取商即可
//



// 一个数组中有三个数字 a、b、c 只出现一次，其他数字都出现了 2 次，请找出这 3 个只出现 1 次的数字
// 题解： 这是 findNumberAppearsOnce 和 findNumberAppearsOnce2 的结合
//
//      首先考虑的是，类似找 2 个元素那样，分出 3 个数组
//      根据 全体异或 的结果，只能分出 2 大类情况，每个大类又包含 2 个子类
//
//          000 -> 0, 011 -> 0
//          001 -> 1, 111 -> 1
//
//      按位遍历所有的数字，按照 0, 1 分别分组
//      因为我们只能处理结果为 1 的情况，所以接下来遍历异或结果为 1 的那些位
//
//          如果是 111, 则跳过此位，因为 a, b, c 在一组，求不出结果
//          如果是 001, 那么此位为 1 的数据可以挑出来 (类似 findNumberAppearsOnce2)
//
//              这样剩下的数据就变成 findNumberAppearsOnce 题型处理的场景了
//

#endif // easy_bitwise_h
