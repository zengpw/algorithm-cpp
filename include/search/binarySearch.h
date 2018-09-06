//
//  binarySearch.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/9/6.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef search_binarySearch_h
#define search_binarySearch_h

#include "include/util/intUtil.h"

int binarySearch(const int array[], const int low, const int high, const int element)
{
    int arraySize = high - low + 1;
    
    // 初始化中间元素位置，如果有 2 个元素在中间位置，则选择 前一个 元素 作为唯一中间元素
    int m = low + (arraySize - 1)/2;
    printELement(array, m);
    
    // 不使用递归，避免性能问题，所以需要缓存子表区间位置
    int l = low;
    int r = high;
    
    while (element != array[m])
    {
        if (element < array[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        
        // 重新计算子表中间元素位置
        m = l + (r - l)/2;
        printELement(array, m);
    }
    
    return m;
}

#endif // search_binarySearch_h
