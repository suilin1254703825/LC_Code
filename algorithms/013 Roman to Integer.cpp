#include "stdafx.h"
using namespace std;

/*
解题思路：
1、分析 1-4000可能出现的符号
{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
{ "", "M", "MM", "MMM" }

MM > M > CM > DC > D > CD > C > XC >LX > L > XL > X > IX > VI > V > IV > I
2、 1)总结现有规律， M D C L X V I这种基本符号的组合；
2)多个连续相同字符，则为加上一倍的对应基数 M = 1000,MM = 2000;
3)CM CD IX 类似字符 低权值数字在前，均为减去低权值基数 CD = 400 D = 500 CM = 900
3)DC LX VI 类似字符 高权值数字在前，均为加上低权值基数 DC = 600 LX = 50 + 10 = 60
4)低权值位于高权值数字前则需减去低权值对应基数，反之为加上。（低权值在前为特殊情况仅有 IX IV XL XC CD CM等六种情况）;
*/
int romanToInt(string s) {
    int nRes = 0;
    int nLen = s.length();
    for (int i = 0; i < nLen; ++i)
    {
        switch (s[i])
        {
        case 'M':
            nRes += 1000;
            break;
        case 'D':
            nRes += 500;
            break;
        case 'C':
            if (i + 1 < nLen && ('D' == s[i + 1] || 'M' == s[i + 1]))
            {
                nRes -= 100;
            }
            else
            {
                nRes += 100;
            }
            break;
        case 'L':
            nRes += 50;
            break;
        case 'X':
            if (i + 1 < nLen && ('L' == s[i + 1] || 'C' == s[i + 1]))
            {
                nRes -= 10;
            }
            else
            {
                nRes += 10;
            }
            break;
        case 'V':
            nRes += 5;
            break;
        case 'I':
            if (i + 1 < nLen && ('X' == s[i + 1] || 'V' == s[i + 1]))
            {
                nRes -= 1;
            }
            else
            {
                nRes += 1;
            }
            break;
        default:
            nRes = -1;
            return nRes;
        }
    }

    return nRes;
}

int romanToInt1(string s) {
    map <char, int> mapRoman2int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
   
    int prevalue = mapRoman2int[s[0]];
    int cur = prevalue;
    int i = 1;
    int ret = cur;

    while ('\0' != s[i])
    {
        cur = mapRoman2int[s[i++]];
        ret += cur;
        if (cur > prevalue)
        {
            ret = ret - (prevalue << 1);
        }
        prevalue = cur;
    }

    return ret;
}

int main()
{
    // romanToInt
    string strRoman = "MVI";
    int nMode = romanToInt(strRoman);
    cout << strRoman << " = " << nMode << endl;

    getchar();
    return 0;
}

