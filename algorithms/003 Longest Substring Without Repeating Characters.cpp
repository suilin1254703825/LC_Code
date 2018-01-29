1#include "stdafx.h"
#include <vector>
#include <hash_map>
using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
int lengthOfLongestSubstring(string s) {
    int nCount = 0;
    int nMax = 0;
    // 使用数组来存储出现的字符的位置
    vector<int> vecTemp(256, -1);
    int nL = 0;
    int nR = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (-1 != vecTemp[s[i]])
        {
            int nNum = vecTemp[s[i]] + 1;
            nL = nNum > nL ? nNum : nL; // 重置不重复元素的最左侧元素索引
        }
        vecTemp[s[i]] = i;
        nCount = i - nL + 1; // 计算当前的最大距离

        nMax = nMax > nCount ? nMax : nCount;
    }

    return nMax;
};
