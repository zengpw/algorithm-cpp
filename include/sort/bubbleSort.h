//
//  bubbleSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "util/intUtil.h"

void bubbleSort(int array[], int low, int high)
{
    int arraySize = high - low + 1;
    
    // 遍历序列的次数
    for (int i = low; i <= high; i++)
    {
        // 遍历区间 [low, high - i]
        for (int j = low; j < high - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapIntArrayElement(array, j, j + 1);
                printIntArray(array, arraySize);
            }
        }
    }
}
