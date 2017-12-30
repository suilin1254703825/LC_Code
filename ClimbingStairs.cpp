// LC_ClimbStair.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

int ClimbStairs(int nNum)
{
	if (nNum <= 2 && 0 <= nNum)
	{
		return nNum;
	}
	else if (nNum > 2)
	{
		return ClimbStairs(nNum - 1) + ClimbStairs(nNum - 2);
	}
}

int climbingStairs(int nNum)
{
	vector<int> vecNum(nNum + 1);
	vecNum[0] = 0;
	vecNum[1] = 1;
	vecNum[2] = 2;
	for (int i = 3; i <= nNum; i++)
	{
		vecNum[i] = vecNum[i - 1] + vecNum[i - 2];
	}

	return vecNum[nNum];
}

int Climbing(int nNum)
{
	int nStairs1 = 1;
	int nStairs2 = 1;
	
	if (nNum < 2) return nNum;

	for (int i = 2; i <= nNum; i++)
	{
		int nTemp = nStairs1;
		nStairs1 = nStairs2;
		nStairs2 = nTemp + nStairs1;
	}
	return nStairs2;
}

int main()
{
	printf("%d\n", ClimbStairs(3));
	printf("%d\n", climbingStairs(5));
	getchar();
    return 0;
}

