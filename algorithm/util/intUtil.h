//
//  intUtil.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#ifndef util_intUtil_h
#define util_intUtil_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <sstream>
#include <string>

static void swapIntArrayElement(int *array, int i, int j)
{
    int k = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = k;
}

static std::string intArray2String(const int *array, int arraySize)
{
    std::stringstream ss;
    std::string arrayString;
    
    for (int i = 0; i < arraySize; i++)
    {
        ss << *(array + i);
        
        arrayString += ss.str();
        
        if (i < arraySize - 1)
        {
            arrayString += " ";
        }
        
        // clear buffer
        ss.str("");
        ss.clear();
    }
    
    return arrayString;
}

static void printIntArray(const int *array, int arraySize)
{
    std::cout << "Array = " << intArray2String(array, arraySize) << std::endl;
}

static void printELement(const int *array, const int element)
{
    std::cout << "key = " << element << ", value = " << *(array + element) << std::endl;
}

#endif // util_intUtil_h
