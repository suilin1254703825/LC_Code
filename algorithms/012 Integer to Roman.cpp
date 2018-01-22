#include "stdafx.h"
using namespace std;

/*
12. Integer to Roman
解题思路：
1、正常来说根据罗马数字的规则，I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
    1)相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
    2)小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
    3)小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；
    4)在一个数的上面画一条横线，表示这个数增值 1,000 倍，如
2、从整数到罗马数字(1 - 3999)，
   栗子： 123 -> CXXIII    444 -> CDXLIV
   
   不难看出和我们的十进制是类似的，但是这里只是分为了十三阶
   （ 1000, 900, 500,  400,  100,  90,  50,   40,  10,    9,   5,    4,  1）
   （ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"）
   由大到小循环递减方式来逐一表示
*/
string intToRoman(int num)
{
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string strScale[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    string strRomanNum = "";
    for (int i = 0; num != 0; ++i)
    {
        while (num >= value[i])
        {
            num -= value[i];
            strRomanNum += strScale[i];
        }
    }
    return strRomanNum;
}


int main()
{
    int nInterger = 1988;
    cout << intToRoman(nInterger) << endl; // MCMLXXXVIII
	getchar();
    return 0;
}

