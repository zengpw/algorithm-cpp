//
//  leet_code_14_longest_common_prefix.h
//  algorithm-cpp
//
//  Created by Vincent Zeng on 2019/5/8.
//  Copyright © 2019 Vincent Zeng. All rights reserved.
//

#ifndef dp_leet_code_14_longest_common_prefix_h
#define dp_leet_code_14_longest_common_prefix_h

#include "util/intUtil.h"
#include "util/leetCodeUtil.h"

using namespace std;

//
//  https://leetcode.com/problems/longest-common-prefix/
//  题意： 最长公共前缀
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

#endif // dp_leet_code_14_longest_common_prefix_h
