//
//  insertionSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/26.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "util/intUtil.h"

void insertionSort(int array[], int low, int high)
{
    int arraySize = high - low + 1;
    
    // 外层无序区 [i, high]
    for (int i = low + 1; i <= high; i++)
    {
        int k = i;
        // 内层有序区 [low, j]
        // 从后往前比较
        for (int j = k - 1; j >= low; j--)
        {
            // 交换是不可避免的，下面2种都可以
            // * 找到位置后，把所有元素后移
            // * 没找到合适位置，往前移动一次
            if (array[k] < array[j])
            {
                swapIntArrayElement(array, k--, j);
                printIntArray(array, arraySize);
            }
            else
            {
                break;
            }
        }
    }
}

