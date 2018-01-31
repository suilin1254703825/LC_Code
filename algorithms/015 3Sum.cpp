#include "stdafx.h"
#include <vector>
using namespace std;

/*
For example, given array S = [-1, 0, 1, 2, -1, -4]
A solution set is:
[
    [-1, 0, 1],
    [-1, -1, 2]
]
*/
vector<vector<int>> threeSum(vector<int>& vecNum) {
    vector<vector<int> > vecRes;
    if (vecNum.size() < 3)
    {
        return vecRes;
    }

    sort(vecNum.begin(), vecNum.end());

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
            if (0 > *iterBg + *iterL + *iterR)
            {
                iterL++;
                while (*iterL == *(iterL - 1) && iterL < iterR)
                {
                    iterL++;
                }
            }
            else if (0 < *iterBg + *iterL + *iterR)
            {
                iterR--;
                while (*iterR == *(iterR + 1) && iterL < iterR)
                {
                    iterR--;
                }
            }
            else
            {
                vecRes.push_back({ *iterBg, *iterL, *iterR });
                iterL++;
                iterR--;
                while (*iterL == *(iterL - 1) && *iterR == *(iterR + 1) && iterL < iterR)
                {
                    iterL++;
                }
            }
        }
    }
    return vecRes;
}

int main()
{
    // test for threeSum
    getchar();
    return 0;
}

