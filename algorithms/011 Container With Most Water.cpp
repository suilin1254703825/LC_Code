#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

/*
11. Container With Most Water
解题思路：
1、最暴力的方式就像遍历这个数组，计算任意两个组合的线段组成的面积大小，不可取；
2、利用左右两边逼夹的方式，向中间运动，记录此时的面积，取最大值。
3、移动时选择较小的边进行移动，并更新记录的两条线段索引。
*/
int maxArea(vector<int>& height) {
    int nMax = 0;
    int nLeft = 0;
    int nRight = height.size() - 1;

    for (; nLeft < nRight;)
    {
        nMax = max(nMax, min(height[nLeft], height[nRight]) * (nRight - nLeft));
        if (height[nLeft] > height[nRight])
        {
            --nRight;
        }
        else
        {
            ++nLeft;
        }
    }

    return nMax;
}

int main()
{
    vector<int> vecHgt = { 3,4,6,3,5,7,8 };

    int nMaxArea = maxArea(vecHgt);
    cout << nMaxArea << endl;
	getchar();
    return 0;
}

