#include "stdafx.h"
#include <vector>
#include <hash_map>
using namespace std;

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/
double findMedianSortedArrays(vector<int>& vecArrayA, vector<int>& vecArrayB) {
    int m = vecArrayA.size();
    int n = vecArrayB.size();

    int nSize = (m + n);
    if (nSize & 0x01)
    {
        return findKth(vecArrayA.begin(), m, vecArrayB.begin(), n, nSize / 2 + 1);
    }
    else
    {
    return (findKth(vecArrayA.begin(), m, vecArrayB.begin(), n, nSize / 2)
            + findKth(vecArrayA.begin(), m, vecArrayB.begin(), n, nSize / 2 + 1)) / 2.0;
    }
}

int findKth(vector<int>::const_iterator iterA, int m, vector<int>::const_iterator iterB, int n, int k)
{
    // 特殊情况处理
    if (m > n)
    {
        return findKth(iterB, n, iterA, m, k);
    }
    if (0 == m)
    {
        return *(iterB + k - 1);
    }
    if (1 == k)
    {
        return *iterA > *iterB ? *iterB : *iterA;
    }

    // 第k个对象存在与两个数组中
    int nA = m > k / 2 ? k / 2 : m;
    int nB = k - nA;
    if (*(iterA + nA - 1) > *(iterB + nB - 1))
    {
        return findKth(iterA, m, iterB + nB, n - nB, k - nB);
    }
    else if (*(iterA + nA - 1) < *(iterB + nB - 1))
    {
        return findKth(iterA + nA, m - nA, iterB, n, k - nA);
    }
    else
    {
        return *(iterA + nA - 1);
    }
}
