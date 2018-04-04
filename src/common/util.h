//
//  util.cpp
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2018/4/4.
//  Copyright © 2018 Vincent Zeng. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

std::string array2String(int array[], int arraySize)
{
    std::stringstream ss;
    std::string arrayString;
    
    for(int i = 0; i < arraySize; i++)
    {
        ss << array[i];
        arrayString += ss.str();
        arrayString += " ";
        
        // clear buffer
        ss.str("");
        ss.clear();
    }
    
    return arrayString;
}

void printArray(int array[], int arraySize)
{
    std::cout << "Array = " << array2String(array, arraySize) << std::endl;
    
    return;
}
