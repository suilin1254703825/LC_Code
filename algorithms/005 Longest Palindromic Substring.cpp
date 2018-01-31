#include "stdafx.h"
#include <string>
using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example:
Input: "babad"
Output: "bab"

Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"
*/
string longestPalindrome(string s)
{
    int nL = 0;
    int nR = 0;
    int nResL = 0;
    int nResR = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        nL = i;
        while (i + 1 < s.size())
        {
            if (s[i] != s[i + 1])
            {
                break;
            }

            ++i;
        }

        nR = i;
        while (nL - 1 >= 0 && nR + 1 < s.size())
        {
            if (s[nL - 1] == s[nR + 1])
            {
                --nL;
                ++nR;
                continue;
            }
            break;
        }

        if (nResR - nResL < nR - nL)
        {
            nResL = nL;
            nResR = nR;
        }
    }

    return s.substr(nResL, nResR - nResL + 1);
}