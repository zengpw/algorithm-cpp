//
//  selectionSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/26.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include "common/intUtil.h"

void selectionSort(int array[], int low, int high)
{
    int arraySize = high - low + 1;
    
    for (int i = low; i <= high; i++)
    {
        int k = i;
        //每次都在区间 [i, high] 中查找最小的
        for (int j = i + 1; j <= high; j++)
        {
            if (array[j] < array[k])
                k = j;
        }
        //假如 array[i] 不是最小的，则交换
        if (k != i)
        {
            swapIntArrayElement(array, i, k);
            printIntArray(array, arraySize);
        }
    }
}

