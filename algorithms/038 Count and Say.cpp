// LC_CountAndSay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

string CountAndSay(int n)
{
	string strSaying = "1";
	for (int i = 1; i < n; i++)
	{
		int nCount = 0;
		string strTemp = "";
		char chTemp = strSaying[0];
		char chIntToStr[10] = { '0' };
		
		for (size_t j = 0; j < strSaying.length(); j++)
		{
			if (chTemp == strSaying[j])
			{
				nCount++;
			}
			else
			{
				sprintf_s(chIntToStr, "%d", nCount);
				//_itoa_s(nCount, chIntToStr, 10);
				strTemp = strTemp + chIntToStr + chTemp;
				chTemp = strSaying[j];
				nCount = 1;
			}

			if (j == strSaying.length() - 1)
			{
				_itoa_s(nCount, chIntToStr, 10);
				strTemp = strTemp + chIntToStr + chTemp;
			}
		}

		strSaying = strTemp;
	}
	return strSaying;
}

int main()
{
	printf("%s", CountAndSay(6).c_str());
	getchar();
    return 0;
}
