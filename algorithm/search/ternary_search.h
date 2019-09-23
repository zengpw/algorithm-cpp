//
//  ternary_search.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/10/17.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef search_ternary_search_h
#define search_ternary_search_h

#include "util/int_util.h"

/**
 *
 *  @param direction        = 0 开口向下的抛物线, = 1 开口向上的抛物线
 *
 */
int ternarySearch(const int array[], const int low, const int high, int direction)
{
    // 初始化 1/3, 2/3 位置
    int m1 = low + (high - low)/3;
    int m2 = high - (high - low)/3;
    
    // 不使用递归，避免性能问题，所以需要缓存子表区间位置
    int l = low;
    int r = high;

    while (true)
    {
//        printELement(array, m1);
//        printELement(array, m2);

        if (m1 == l && m2 == r)
        {
            return m1 + 1;
        }

        if (array[m1] < array[m2])
        {
            direction == 0 ? l = m1 : r = m2;
        }
        else
        {
            direction == 0 ? r = m2 : l = m1;
        }

        m1 = l + (r - l)/3;
        m2 = r - (r - l)/3;
    }
}

#endif // search_ternary_search_h
