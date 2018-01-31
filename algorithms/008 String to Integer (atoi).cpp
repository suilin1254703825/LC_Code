#include "stdafx.h"
#include <limits>
using namespace std;

/*
// NO8.String to Integer (atoi)
// atoi功能详述：
// 1、跳过前面的空白字符（例如空格，tab缩进等，可以通过isspace( )函数来检测）；
// 2、直到遇上数字或正负符号才开始做转换；
// 3、再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回；
// 4、如果 nptr不能转换成 int 或者 nptr为空字符串，那么将返回 0；
// 思路：
// 1、遍历字符串依次判断字符。
// 2、跳过未检出数字的字符的前置空格缩进符号等；
// 3、检测是否存在数字正负号问题，正负号有且只能被检测到一次；
// 4、检测到非数字或字符串检测结束时，返回结果；
// 5、若字符串为空或不能转换成int时，返回0；
// 6、 如果正确的值超出可表示值的范围，则返回INT_MAX（2147483647）或INT_MIN（-2147483648）
*/
int myAtoi(string str)
{ // 12ms
    long long llValue = 0;
    bool bNeg = false;

    int nIndex = 0;
    int nLen = str.size();

    if (0 == nLen)
    {
        return 0;
    }

    while (isspace(str[nIndex]))
    {
        ++nIndex;
    }

    if (nIndex < nLen && ('-' == str[nIndex] || '+' == str[nIndex]))
    {
        bNeg = '-' == str[nIndex];
        ++nIndex;
    }

    if (nIndex < nLen && str[nIndex] >= '0' && str[nIndex] <= '9')
    {
        llValue = str[nIndex] - '0';
        ++nIndex;
        while (nIndex < nLen && str[nIndex] >= '0' && str[nIndex] <= '9')
        {
            llValue = llValue * 10 + (str[nIndex] - '0');
            ++nIndex;
            if (llValue > INT_MAX)
            {
                return bNeg ? INT_MIN : INT_MAX;
            }
        }

        return bNeg ? -llValue : llValue;
    }

    return 0;
}

int myAtoi1(string str)
{ // 19ms
    int index = 0;
    long long lValue = 0;
    bool bNeg = false;

    while (isspace(str[index]))
    {
        ++index;
    }

    if (index < str.size() && ('-' == str[index] || '+' == str[index]))
    {
        bNeg = '-' == str[index];
        ++index;
    }

    for (; index < str.size(); index++)
    {
        if (str[index] >= '0' && str[index] <= '9')
        {
            lValue = lValue * 10 + str[index] - '0';
            if (lValue > INT_MAX)
            {
                return bNeg ? INT_MIN : INT_MAX;
            }
        }
        else
        {
            break;
        }
    }
    return lValue = bNeg ? -lValue : lValue;
}
int main()
{
    cout << myAtoi("-123 123") << endl; // -123
    cout << myAtoi("-2147483648") << endl; // -2147483648
    cout << myAtoi("2147483647") << endl; // 2147483647
    cout << myAtoi1("-123 123") << endl; // -123
    cout << myAtoi1("-2147483648") << endl; // -2147483648
    cout << myAtoi1("2147483647") << endl; // 2147483647

    getchar();
    return 0;
}
