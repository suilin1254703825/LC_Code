#include "stdafx.h"
#include <vector>
#include <hash_map>
using namespace std;

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/
vector<int> twoSum(vector<int>& vecNum, int nTarget) {
    vector<int> vecTemp;
    unordered_map<int, int> hashMapTemp;

    for (int i = 0; i < vecNum.size(); i++)
    {
        hashMapTemp[vecNum[i]] = i;
    }

    for (int i = 0; i < vecNum.size(); i++)
    {
        const int nPart = nTarget - vecNum[i];
        if (hashMapTemp.find(nPart) != hashMapTemp.end() && hashMapTemp[nPart] > i)
        {
            vecTemp.push_back(i);
            vecTemp.push_back(hashMapTemp[nPart]);
            break;
        }
    }

    return vecTemp;
}
