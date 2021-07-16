//
//  leet_code_tree_util.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2021/7/16.
//  Copyright © 2021 Vincent Zeng. All rights reserved.
//

#ifndef test_util_h
#define test_util_h

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class arrayUtil
{
public:
    static bool existsInArray(const int *array, int arraySize, int value)
    {
        for (int i = 0; i < arraySize; ++i)
        {
            if (array[i] == value)
                return true;
        }

        return false;
    }
};

class stlUtil
{
public:
    template <typename T>
    static std::string vector2String(std::vector<T> &v)
    {
        std::stringstream ss;
        std::string resultString;

        for (int i = 0; i < v.size(); ++i)
        {
            ss << v[i];
            resultString += ss.str();

            if (i < v.size() - 1)
            {
                resultString += " ";
            }

            // clear buffer
            ss.str("");
            ss.clear();
        }

        return resultString;
    }

    template <typename T>
    static std::string vectorVector2String(std::vector<std::vector<T>> &vv)
    {
        std::stringstream ss;
        std::string resultString;

        for (int i = 0; i < vv.size(); ++i)
        {
            for (int j = 0; j < vv[i].size(); ++j)
            {
                ss << vv[i][j];
                resultString += ss.str();

                if (j < vv[i].size() - 1)
                {
                    resultString += " ";
                }

                // clear buffer
                ss.str("");
                ss.clear();
            }

            if (i < vv.size() - 1)
            {
                resultString += "; ";
            }
        }

        return resultString;
    }

    template <typename T>
    static void printVectorVector(std::vector<std::vector<T>> &vv)
    {
        std::cout << "Vector = " << vectorVector2String<T>(vv) << std::endl;
    }

    template <typename T>
    static void vectorVector2StringVector(std::vector<std::vector<T>> &vv, std::vector<std::string> &output)
    {
        for (auto &v : vv)
        {
            output.push_back(vector2String(v));
        }
    }
};

#endif // test_util_h
