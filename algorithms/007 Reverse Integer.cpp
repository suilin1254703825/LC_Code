#include "stdafx.h"
#include <limits>
#include <vector>
using namespace std;

/*
Reverse digits of an integer
题意：判断输入的一个有符号整型数字，倒序输出
思路：
  题意:判断输入的一个有符号整型数字，倒序输出
  思路:将每个字符存储，%取余 整除取出每一个数位的大小。
  对于取出来的每个数位进行反向组合 12132 -》23121，这里特别说明使用long long存储
  如何判断越界问题：long long 存储数据与 INI_MAX INI_MIN边界对比，越界则返回0;
  备注: limits.h 中有define INI_MAX INI_MIN
*/
int reverseEx(int x) {
    if (x < 10 && x > -10)
    {
        return x;
    }

    vector<int> vecNum(10, 0); // 十位数字存储即可
    int nIndex = 0;
    while (0 != x)
    {
        vecNum[nIndex++] = x % 10;
        x /= 10;
    }

    int nBgn = 0;
    long long nTemp = 0;
    while (nBgn < nIndex)
    {
        nTemp = nTemp * 10 + vecNum[nBgn];
        ++nBgn;
    }

    if (nTemp > INT_MAX || nTemp < INT_MIN)
    {
        return 0;
    }

    return nTemp;
}

int reverseEx2(int x)
{
    long llTmp = 0;
    while (x != 0)
    {
        llTmp = llTmp * 10 + x % 10;
        if (llTmp > INT_MAX || llTmp < INT_MIN)
        {
            return 0;
        }
        x /= 10;
    }

    return llTmp;
}

int reverse(int x) {
    long answer = 0;
    while (x != 0) {
        answer = answer * 10 + x % 10;
        if (answer > INT_MAX || answer < INT_MIN) return 0;
        x /= 10;
    }
    return (int)answer;
}
int main()
{

    cout << reverse(-123) << endl; // 321

    getchar();
    return 0;
}

