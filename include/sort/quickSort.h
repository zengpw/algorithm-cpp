//
//  quickSort.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/28.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef sort_quickSort_h
#define sort_quickSort_h

#include "util/intUtil.h"

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

//// 快速排序（3分区法）
//// 3分区法是指单独处理与中轴相等的元素
//// 将与中轴相等的元素移动到最左边和最右边，直到 i 与 j 相遇后才将元素交换到中间
//void quickSort3Way(int array[], int low, int high)
//{
//    // 如果序列大小为1，则退出
//    if (low >= high)
//        return;
//
//    // 选择中轴的值
//    int pivot = array[low];
//    // 待排序的序列区间
//    int i = low + 1;
//    int j = high;
//    // 最左边及最右边与中轴等值的区间
//    int l = i;
//    int r = j;
//
//    // 扫描序列，与中轴进行比较
//    for (;;)
//    {
//        // array[i] 从左至右和 pivot 比较，如果小于等于 pivot, 则 i++, 否则 i 不变
//        while (array[i] <= pivot && i <= j)
//        {
//            if (array[i] == pivot)
//            {
//                swapIntArrayElement(array, l++, i);
//            }
//
//            i++;
//        }
//        // array[j] 从右至左和 pivot 比较，如果大于等于 pivot, 则 j--, 否则 j 不变
//        while (array[j] >= pivot && j > i)
//        {
//            if (array[j] == pivot)
//            {
//                swapIntArrayElement(array, r--, j);
//            }
//
//            j--;
//        }
//
//        // 交换 i 和 j 的值
//        if (i < j)
//            swapIntArrayElement(array, i, j);
//        else
//            break;
//    }
//
//    // 只有在中轴大于左区间最大值的情况下，才移动中轴
//    if (pivot > array[j])
//        swapIntArrayElement(array, low, j);
//
//    // 左右区间 [l, j] - [i, r]，等值区间 [low+1, --l] - [++r, high]
//    // 需要将等值区间移动到 [j, i]
//    // 移动与中轴相等的元素
//    while (l < j && l > (low + 1))
//        swapIntArrayElement(array, j--, --l);
//
//    while (r > i && r < high)
//        swapIntArrayElement(array, i++, ++r);
//
//    quickSort3Way(array, ++l, j);
//    quickSort3Way(array, i, r);
//}

#endif // sort_quickSort_h
