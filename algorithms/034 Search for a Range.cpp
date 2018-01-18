#include "stdafx.h"
#include <vector>
using namespace std;
/*
* @brief: 34. Search for a Range
* runtime complexity must be in the order of O(log n).
*/
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> vecTmp = { -1 , -1 };
    // is null
    if (nums.empty())
    {
        return vecTmp;
    }

    if (1 == nums.size())
    {
        if (target == nums[0])
        {
            vecTmp[0] = 0;
            vecTmp[1] = 0;
        }
        return vecTmp;
    }

    // binary foreach the target index
    int index = 0;
    int nBegin = 0;
    int nEnd = nums.size() - 1;
    int nHit = -1;
    while (nBegin <= nEnd)
    {
        index = (nBegin + nEnd) / 2;
        if (nums[index] > target)
        {
            nEnd = index - 1;
        }
        else if (nums[index] < target)
        {
            nBegin = index + 1;
        }
        else
        {
            nHit = index;
            vecTmp[0] = nHit;
            vecTmp[1] = nHit;
            break;
        }
    }

    if (-1 != nHit)
    {
        // left
        nBegin = 0;
        nEnd = nHit - 1;
        while (nBegin <= nEnd)
        {
            index = (nBegin + nEnd) / 2;
            if (nums[index] < target)
            {
                nBegin = index + 1;
            }
            else
            {
                vecTmp[0] = index;
                nEnd = index - 1;
            }
        }

        // right
        nBegin = nHit + 1;
        nEnd = nums.size() - 1;
        while (nBegin <= nEnd)
        {
            index = (nBegin + nEnd) / 2;
            if (nums[index] > target)
            {
                nEnd = index - 1;
            }
            else
            {
                vecTmp[1] = index;
                nBegin = index + 1;
            }
        }
    }
    return vecTmp;
}


int main()
{

    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    vector<int> res = searchRange(nums, 8);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;

    getchar();
    return 0;
}

