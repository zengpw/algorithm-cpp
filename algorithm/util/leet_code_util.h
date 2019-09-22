//
//  leet_code_util.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/2/28.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef util_leet_code_util_h
#define util_leet_code_util_h

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class stlUtil
{
public:
    template <typename T>
    static std::string vectorVector2String(std::vector<std::vector<T>>& vv)
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
    static void printVectorVector(std::vector<std::vector<T>>& vv)
    {
        std::cout << "Vector = " << vectorVector2String<T>(vv) << std::endl;
    }

    template <typename T>
    static std::string vector2String(std::vector<T>& v)
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
    void clearQueue(std::queue<T>& q) {
        std::queue<T> empty;
        swap(empty, q);
    }
};

namespace treeUtil
{
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
}

#endif // util_leet_code_util_h
