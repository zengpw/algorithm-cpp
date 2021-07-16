//
//  leet_code_14_longest_common_prefix.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/8.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef string_leet_code_14_longest_common_prefix_h
#define string_leet_code_14_longest_common_prefix_h

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//
//  https://leetcode.com/problems/longest-common-prefix/
//  题意： 求最长公共前缀，普通 string 题型，暴力循环 + 排除法
//
class Solution14
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string result = "";

        if (strs.empty())
            return "";

        for (int endPos = 1; endPos <= strs[0].size(); ++endPos)
        {
            result = strs[0].substr(0, endPos);

            for (auto& str : strs)
            {
                if (str.size() < endPos || result != str.substr(0, endPos))
                    return result.substr(0, endPos - 1);
            }
        }

        return result;
    }
};

#endif // string_leet_code_14_longest_common_prefix_h
