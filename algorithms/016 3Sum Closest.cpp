#include "stdafx.h"
#include <vector>
using namespace std;
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.

For example, given array S = { -1 2 1 - 4 }, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
https://leetcode.com/problems/3sum-closest/#/description
*/
int threeSumClosest(vector<int>& vecNum, int nTarget) {
    if (vecNum.size() < 3)
    {
        return INT_MAX;
    }
    sort(vecNum.begin(), vecNum.end());

    int nDiff = INT_MAX;

    for (vector<int>::iterator iterBg = vecNum.begin(); iterBg < vecNum.end() - 2; iterBg++)
    {
        if (iterBg > vecNum.begin() && *(iterBg - 1) == *iterBg)
        {
            continue;
        }

        vector<int>::iterator iterL = iterBg + 1;
        vector<int>::iterator iterR = vecNum.end() - 1;

        while (iterL < iterR)
        {
            int nSum = *iterBg + *iterL + *iterR;
            if (nTarget > nSum)
            {
                iterL++;
                while (*iterL == *(iterL - 1) && iterL < iterR)
                {
                    iterL++;
                }
            }
            else if (nTarget < nSum)
            {
                iterR--;
                while (*iterR == *(iterR + 1) && iterL < iterR)
                {
                    iterR--;
                }
            }
            else
            {
                return nTarget;
            }

            int nTemp = abs(nTarget - nSum);
            if (abs(nDiff) > nTemp)
            {
                nDiff = nTarget - nSum;
            }
        }
    }

    return nTarget - nDiff;

}
int main()
{

    vector<int> nums = { -1, 2, 1, - 4 };
    int tmp = threeSumClosest(nums, -1 ); // -1 + 2 + 1 = 2
    cout << tmp << endl;

    getchar();
    return 0;
}

