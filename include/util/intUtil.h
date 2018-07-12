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

void swapIntArrayElement(int *array, int i, int j)
{
    int k = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = k;
    
    return;
}

std::string intArray2String(const int *array, int arraySize)
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

void printIntArray(const int *array, int arraySize)
{
    std::cout << "Array = " << intArray2String(array, arraySize) << std::endl;
    return;
}

#endif // util_intUtil_h

