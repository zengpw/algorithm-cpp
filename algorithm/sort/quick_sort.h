//
//  quick_sort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_quick_sort_h
#define sort_quick_sort_h

#include "util/int_util.h"

// 快速排序（2分区法）
void quickSort(int array[], int low, int high)
{
    // 如果序列大小为1，则退出
    if (low >= high)
        return;
    
    // 选择中轴的值
    int pivot = array[low];
    // 待排序的序列区间
    int i = low + 1;
    int j = high;
    
    // 扫描序列，与中轴进行比较
    // 存在2种场景：
    //  * 被中轴分成2个区间
    //  * 所有数据都比中轴大，最后只存在右区间
    for (;;)
    {
        // array[i] 从左至右和 pivot 比较，如果小于等于 pivot, 则 i++, 否则 i 不变
        while (array[i] <= pivot && i <= j)
            i++;
        // array[j] 从右至左和 pivot 比较，如果大于 pivot, 则 j--, 否则 j 不变
        while (array[j] > pivot && j > i)
            j--;
        // 交换 i 和 j 的值
        if (i < j)
            swapIntArrayElement(array, i, j);
        else
            break;
    }
    
    // 只有在中轴大于左区间最大值的情况下，才移动中轴
    if (pivot > array[j])
    {
        swapIntArrayElement(array, low, j);
    }
    
    quickSort(array, low, j - 1);
    quickSort(array, i, high);
}

#endif // sort_quick_sort_h
