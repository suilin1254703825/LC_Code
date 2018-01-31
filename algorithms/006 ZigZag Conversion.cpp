#include "stdafx.h"
#include <vector>
using namespace std;

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Subscribe to see which companies asked this question.

Solution1:
 题目的意思是把字符串上下上下走之字形状,然后按行输出,比如包含数字0~22的字符串, 给定行数为5,走之字形如下:
 0       8           16
 1     7 9        15 17
 2   6   10    14    18
 3 5     11 13       19
 4       12          20
现在要按行输出字符,即:0 8 16 1 7 9 15 17 2…….
如果把以上的数字字符看做是字符在原数组的下标, 给定行数为n = 5, 可以发现以下规律:
(1)第一行和最后一行下标间隔都是interval = n*2-2 = 8 ;
(2)中间行的间隔是周期性的,第i行的间隔是: interval–2*i,  2*i,  interval–2*i, 2*i, interval–2*i, 2*i, …
*/
string convert(string s, int nRows) {
    if (nRows == 1)return s;
    int len = s.size(), k = 0, interval = (nRows << 1) - 2;
    string res(len, ' ');
    for (int j = 0; j < len; j += interval)//处理第一行
        res[k++] = s[j];
    for (int i = 1; i < nRows - 1; i++)//处理中间行
    {
        int inter = (i << 1);
        for (int j = i; j < len; j += inter)
        {
            res[k++] = s[j];
            inter = interval - inter;
        }
    }
    for (int j = nRows - 1; j < len; j += interval)//处理最后一行
        res[k++] = s[j];
    return res;
}
/*

通过研究规律发现如下：

0    4       8
1 3  5   7   9
2    6      10
0 - 22 为字符的数组索引
由于新的数组次序为 048 13579 26 10的次序，
不能得出寻找其中的规律进行读写：

开始遍历 写入数组  1 ---- nRows
第一行  i = 1
0 8 16    每一列间隔为 interval = nRows * 2 - 2;
nRule = interval*(nColumn ) + (i - 1)
{
nIndex= 0; nColumn = 0
// 1、 strTemp[ nIndex] = s[interval*(nColumn - 1)];
// 2、 nIndex++;nColumn++;
// 3、 判断nIndex是否interval*(nColumn - 1)是否 大于传入的字符串长度nLenth
// 4、 大则跳出本段循环，进行一下行写。
}

中间行  i = 2 ... nRows - 1
i = 2       1 7  9  15 17    interval*(nColumn - 1) + i  、 interval*(nColumn - 1) - i
i = 3       2 6 10 14 18     interval*(nColumn - 1) + i  、 interval*(nColumn - 1) - i

int nRule = interval * ((nColumn + 1) / 2) + (i - 1) * (nColumn % 2 ? -1 : 1)  0 + 1 = 1

{
nColumn = 0
// 1、 strTemp[ nIndex] = s[interval*(nColumn - 1)];
// 2、 nIndex++;nColumn++;
// 3、 判断nIndex是否 nRule是否 大于传入的字符串长度nLenth
// 4、 大则跳出本段循环，进行一下行写。
}

最后行  i = nRows
0 8 16    每一列间隔为 interval = nRows * 2 - 2;
int nRule = interval*(nColumn ) + (i - 1)
{
nColumn = 0
// 1、 strTemp[ nIndex] = s[interval*(nColumn - 1)];
// 2、 nIndex++;nColumn++;
// 3、 判断nIndex是否interval*(nColumn - 1)是否 大于传入的字符串长度nLenth
// 4、 大则跳出本段循环，进行一下行写。
}
*/

string convertEx(string s, int numRows) {
    int nLen = s.size();
    if (1 == nLen || 1 == numRows)
    {
        return s;
    }
    string strRes(nLen, ' ');
    int nRow = 0;
    int nColumn = 0;
    int nRule = 0;
    int nInterval = (numRows << 1) - 2; // 移位代替 * 2
    int nIndex = 0;
    /*
    首行：     nRule = interval*(nColumn) + nRow
    中间行：   nRule = interval * ((nColumn + 1) / 2) + nRow * (nColumn % 2 ? -1 : 1)  0 + 1 = 1
    尾行：     nRule = interval*(nColumn) + nRow
    */
    while (nRow < numRows)
    {
        if (0 == nRow)
        {
            nColumn = 0;
            nRule = nInterval * nColumn;
            while (nRule < nLen)
            {
                strRes[nIndex] = s[nRule];
                ++nColumn;
                ++nIndex;
                nRule = nInterval * nColumn;
            }
        }
        else if (nRow < numRows - 1)
        {
            nColumn = 0;
            nRule = nInterval * ((nColumn + 1) >> 1) + nRow * (nColumn % 2 ? -1 : 1);
            while (nRule < nLen)
            {
                strRes[nIndex] = s[nRule];
                ++nColumn;
                ++nIndex;
                nRule = nInterval * ((nColumn + 1) >> 1) + nRow * (nColumn % 2 ? -1 : 1);
            }
        }
        else
        {
            nColumn = 0;
            nRule = nInterval * nColumn + nRow;
            while (nRule < nLen)
            {
                strRes[nIndex] = s[nRule];
                ++nColumn;
                ++nIndex;
                nRule = nInterval * nColumn + nRow;
            }
        }
        ++nRow;
    }
    return strRes;
}

string convertEx2(string s, int numRows) {
    int nLen = s.size();
    if (1 == nLen || 1 == numRows)
    {
        return s;
    }
    string strRes(nLen, ' ');
    int nInterval = (numRows << 1) - 2; // 移位代替 * 2
    int nIndex = 0;
    // 首行 间隔为 nInterval
    for (int i = 0; i < nLen; i += nInterval)
    {
        strRes[nIndex++] = s[i];
    }
    // 中间行 间隔为  nInterval - 2 * i 与 2 * i交替
    for (int i = 1; i < numRows - 1; i++)
    {
        int nInterTemp = i << 1;
        for (int j = i; j < nLen; j += nInterTemp)
        {
            strRes[nIndex++] = s[j];
            nInterTemp = nInterval - nInterTemp; // 和为nInterval 互补
        }
    }
    // 尾行 间隔为 nInterval
    for (int i = numRows - 1; i < nLen; i += nInterval)
    {
        strRes[nIndex++] = s[i];
    }
    return strRes;
}

int main()
{
    cout << convert("PAYPALISHIRING", 3) << endl; // PAHNAPLSIIGYIR
    cout << convertEx("PAYPALISHIRING", 3) << endl; // PAHNAPLSIIGYIR
    cout << convertEx2("PAYPALISHIRING", 3) << endl; // PAHNAPLSIIGYIR

    getchar();
    return 0;
}
