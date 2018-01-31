#include "stdafx.h"
#include <limits>
using namespace std;

/*
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack
*/

int strStr1(string haystack, string needle) {
    if (needle.empty())
    {
        return 0;
    }
    if (needle.size() > haystack.size())
    {
        return -1;
    }
    int nIndex = 0;
    bool bFlag = false;
    for (int i = 0; i < haystack.size(); ++i)
    {
        if (0 == i)
        {
            nIndex = i;
        }
        if (haystack[i] != needle[i - nIndex])
        {
            if (nIndex != i)
            {
                i = nIndex;
            }
            nIndex = i + 1;
        }
        else if (needle.size() - 1 == i - nIndex)
        {
            bFlag = true;
            break;
        }
    }
    if (nIndex < haystack.size() && bFlag)
    {
        return nIndex;
    }
    else
    {
        return -1;
    }
}

int strStr2(string haystack, string needle) {
    int nLenFa = haystack.size();
    int nLenSon = needle.size();
    if (0 == nLenSon)
    {
        return 0;
    }
    for (int i = 0; i < nLenFa; ++i)
    {
        int j = 0;
        for (; j < nLenSon; ++j)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }
        if (nLenSon == j)
        {
            return i;
        }
    }
    return -1;
}

int strStr(string haystack, string needle)
{
    return haystack.find(needle);
}

int main()
{
    strStr("hello", "ll"); // 2
    strStr1("hello", "ll"); // 2
    strStr2("hello", "ll"); // 2
    strStr("aaaaa", "bba"); // -
    strStr1("aaaaa", "bba"); // -1
    strStr2("aaaaa", "bba"); // -1
    getchar();
    return 0;
}
