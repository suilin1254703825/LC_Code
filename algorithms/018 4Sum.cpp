#include "stdafx.h"
#include <vector>
using namespace std;

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.
*/

/*
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
]
*/
vector<vector<int>> fourSum(vector<int>& vecNum, int nTarget) {
    vector<vector<int> > vecRes;
    if (vecNum.size() < 4)
    {
        return vecRes;
    }

    sort(vecNum.begin(), vecNum.end());

    unordered_multimap<int, pair<int, int>> mapTemp;

    for (size_t i = 0; i < vecNum.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < vecNum.size(); ++j)
        {
            mapTemp.insert(make_pair(vecNum[i] + vecNum[j], make_pair(i, j)));
        }
    }

    for (auto iterBg = mapTemp.begin(); iterBg != mapTemp.end(); ++iterBg)
    {
        int nRemaind = nTarget - iterBg->first;
        auto mapRange = mapTemp.equal_range(nRemaind);

        for (auto iterRangeBgn = mapRange.first; iterRangeBgn != mapRange.second; ++iterRangeBgn)
        {
            int nOne = iterBg->second.first;
            int nTwo = iterBg->second.second;
            int nThree = iterRangeBgn->second.first;
            int nFour = iterRangeBgn->second.second;
            if (nOne != nThree && nOne != nFour && nTwo != nThree && nTwo != nFour)
            {
                vector<int> vecTemp = { vecNum[nOne], vecNum[nTwo], vecNum[nThree], vecNum[nFour] };
                sort(vecTemp.begin(), vecTemp.end());
                vecRes.push_back(vecTemp);
            }
        }
    }

    sort(vecRes.begin(), vecRes.end());
    vecRes.erase(unique(vecRes.begin(), vecRes.end()), vecRes.end());

    return vecRes;
}

int main()
{
    vector<string> nums = { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> ret = fourSum(nums, 0);
    for (int tmp in ret)
    {
        cout << tmp << endl;
    }

    getchar();
    return 0;
}

