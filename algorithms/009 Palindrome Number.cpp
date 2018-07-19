#include "stdafx.h"
using namespace std;
/*
Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints:Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
Solution1:
 1、利用long long来存储 逆序的数，在进行比较；
 2、将回文数分成中值前后的两部分再进行比较；
*/
bool isPalindrome(int x) {
    long long nValue = 0;
    int nTemp = x;
    if (nTemp < 0)
    {
        return false;
    }
    while (0 != nTemp / 10)
    {
        nValue = nValue * 10 + nTemp % 10;
        nTemp /= 10;
    }
    nValue = nValue * 10 + nTemp % 10;
    if (nValue == x)
    {
        return true;
    }
    return false;
}

bool isPalindromeEx(int x) {
    if (x < 0)
    {
        return false;
    }
    int nLen = 0;
    int nTemp = x;
    while (0 != nTemp)
    {
        nTemp /= 10;
        ++nLen;
    }
    nTemp = x;
    int nValue = 0;
    int nHalf = nLen / 2;
    while (0 != nHalf)
    {
        nValue = nValue * 10 + (nTemp % 10);
        nTemp /= 10;
        --nHalf;
    }
    if (1 == nLen % 2)
    {
        nTemp /= 10;
    }
    return nTemp == nValue;
}

bool isPalindromeEx2(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
    {
        return false;
    }

    int nValue = 0;
    while (x > nValue)
    {
        nValue = nValue * 10 + (x % 10);
        x /= 10;
    }

    return (x == nValue) || (x == (nValue / 10));

}

/*
9. Palindrome Number 回文数
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true
 */
bool isPalindromeEx3(int x) {
    if (x < 0)
    {
        return false;
    }

    int a = 0;
    int b = x;
    while (b)
    {
        a = a * 10 + b % 10;
        b /= 10;
    }

    return a == x;
}

int main()
{

    cout << isPalindrome(1991) << endl; // 1
    cout << isPalindrome(1988) << endl; // 0
    cout << isPalindromeEx(1991) << endl; // 1
    cout << isPalindromeEx(1988) << endl; // 0
    cout << isPalindromeEx2(1991) << endl; // 1
    cout << isPalindromeEx2(1988) << endl; // 0

    getchar();
    return 0;
}
