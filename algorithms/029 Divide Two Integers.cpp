#include "stdafx.h"
#include <limits>
using namespace std;

/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.

*/

/*
* brief: 不使用乘除模运算进行除法运算
* param[in]: dividend 被除数
* param[in]: divisor 除数
* Solution:
1、在不能使用乘除法的情况，首先都会想到利用加减法来代替乘除进行运算。
2、此处实现除法的功能，通过使用减法，找出倍数关系。
3、毫无疑问如果直接使用循环使用减法实现，必然会导致超时。
4、
*/
int divide3(int dividend, int divisor)
{
    bool bNeg = (dividend < 0) ^ (divisor < 0);
    long long lDividend = abs((long long)dividend);
    long long lDivisor = abs((long long)divisor);
    int nRes = 0;
    while (lDividend >= lDivisor)
    {
        long long nTemp = lDivisor;
        int cCout = 1;
        while (lDividend > nTemp << 1)
        {
            nTemp = nTemp << 1;
            cCout <<= 1;
        }
        nRes += cCout;
        lDividend -= nTemp;
        if (INT_MIN == nRes)
        {
            return nRes = bNeg ? INT_MIN : INT_MAX;
        }
    }
    return bNeg ? -nRes : nRes;
}

int divide(int dividend, int divisor)
{
    bool bNeg = (dividend < 0) ^ (divisor < 0);
    long long lDividend = abs((long long)dividend);
    long long lDivisor = abs((long long)divisor);
    int nRes = 0;
    long long nTemp = lDivisor;
    int cCout = 1;
    while (lDividend > nTemp << 1)
    {
        nTemp = nTemp << 1;
        cCout <<= 1;
    }
    while (lDividend >= lDivisor)
    {
        if (lDividend - nTemp < 0)
        {
            nTemp >>= 1;
            cCout >>= 1;
            continue;
        }
        nRes += cCout;
        lDividend -= nTemp;
        nTemp >>= 1;
        cCout >>= 1;
        if (lDivisor == lDividend)
        {
            nRes += 1;
            lDividend -= lDivisor;
        }
        if (INT_MIN == nRes)
        {
            return nRes = bNeg ? INT_MIN : INT_MAX;
        }
    }
    return bNeg ? -nRes : nRes;
}

int divide1(int dividend, int divisor)
{
    if (INT_MIN == divisor && INT_MIN == dividend)
    {
        return 1;
    }
    if (INT_MIN == divisor || 0 == dividend)
    {
        return 0;
    }
    if (divisor == 0) return INT_MAX;
    bool bNeg = false;
    bool bOverflower = false;
    if ((dividend > 0 && divisor < 0) || (divisor > 0 && dividend < 0))
    {
        bNeg = true;
    }
    unsigned int uDividend = abs(dividend);
    unsigned int uDivisor = abs(divisor);
    long long nRes = 0;
    int n = 1;
    if (uDividend == uDivisor)
    {
        return bNeg ? -1 : 1;
    }
    unsigned long long nTemp2 = uDivisor << n;
    while (uDividend >= nTemp2 && nTemp2 != 0 && nTemp2 != 1)
    {
        ++n;
        nTemp2 = uDivisor << n;
    }
    while (uDividend >= uDivisor)
    {
        unsigned int nTemp = 1;
        unsigned long long nTemp2 = uDivisor << n;
        if (uDividend >= uDivisor << n && 0 != nTemp2 && 1 != nTemp2)
        {
            nTemp2 = uDivisor << n;
            nRes += nTemp << n;
            uDividend -= uDivisor << n;
        }
        --n;
        if (uDivisor == uDividend)
        {
            nRes = nRes + 1;
            break;
        }
    }
    if (INT_MIN == -nRes && !bNeg)
    {
        return INT_MAX;
    }
    return bNeg ? -nRes : nRes;
}

int divide2(int dividend, int divisor) {
    bool negative = (dividend < 0) ^ (divisor < 0);
    int res = 0;
    long long high = abs((long long)dividend);
    long long low = abs((long long)divisor);
    while (high >= low) {
        long long x = low, count = 1;
        while (x < high >> 1) {
            x <<= 1;
            count <<= 1;
        }
        res += count;
        high -= x;
        if (res == INT_MIN) {
            return res = negative ? INT_MIN : INT_MAX;
        }
    }
    return res = negative ? -res : res;
}

int main()
{
    cout << divide(INT_MIN, INT_MIN) << endl;
    cout << divide1(INT_MAX, 1) << endl;
    cout << divide2(INT_MAX, INT_MAX) << endl;
    cout << divide3(100, INT_MAX) << endl;


    cout << divide(1988, 4) << endl;
    cout << divide1(1988, 3) << endl;
    cout << divide2(1988, 2) << endl;
    cout << divide3(1988, 1) << endl;

    getchar();
    return 0;
}
