#include "stdafx.h"
#include <vector>
using namespace std;

/*
Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints:Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Solution1:
// 1、s、p从0开始相互匹配，当且仅当p匹配至结尾时，s也匹配至结尾后才显示匹配成功；
// 2.1 判断p是否匹配至结尾，若为结尾判断s是否为结尾。
// 2.2 判断当前索引的下一字符是否为'*'：
// 2.2.1 若下一字符不为'*'，则判断当前字符是否匹配成功p[nIndexP] == '.' || p[nIndexP] == s[nIndexS]
// 2.2.1.1 当前字符匹配成功则两字符串索引累加，递归匹配下一字节是否匹配；
// 2.2.1.2 若匹配失败，返回匹配失败；
// 2.2.2 若下一字符为'*'，则将递归匹配 nIndexP + 2 字符与 s字符串的剩余部分。
// 2.2.2.1 成功则匹配成功，失败则回溯当前状态；
// 2.2.2.2 失败回溯则，s字符串累加1后，继续重复2.2.2步骤。
// 2.2.2.3 直至* 将所有s中与前一字符相同的字符全部匹配，匹配p中'*'后剩余字符串与s剩余字符串递归2.1步骤
// 备注：若为正则表达式则此处为匹配任意字符都可以，而不是匹配p的前一字符
// 2.2.2 若下一字符为'*'，则判断(p[nIndexP] == '.' || p[nIndexP] == s[nIndexS] && nIndexS < s.size()))
// 依次匹配s的字符，直至匹配到s字符不等于p当前字符或s结尾部分。
// 若下一字符为'*'，则用 匹配 nIndexP + 2 字符与 s字符串的剩余部分进行匹配，若匹配成功，则成功。
// 反之累加s字符索引，右移一个位重复是
// 2.2.2.1 则判断当前字符是否相等 并且 nIndexS是否越界

*/

bool match(string s, string p, int nIndexS, int nIndexP)
{
    // p 是否匹配到结尾，当且仅当 s、p同时到结尾部分才匹配成功
    int nLenS = s.length();
    int nLenP = p.length();
    if (nIndexP == nLenP)
    {
        return nIndexS == nLenS;
    }
    if (p[nIndexP + 1] != '*')
    {
        if (p[nIndexP] == s[nIndexS] || p[nIndexP] == '.')
        {
            ++nIndexP;
            ++nIndexS;
            return match(s, p, nIndexS, nIndexP);
        }
        return false;
    }
    else
    {
        while (p[nIndexP] == s[nIndexS] || p[nIndexP] == '.' && nIndexS < nLenS)
        {
            if (match(s, p, nIndexS, nIndexP + 2))
            {
                return true;
            }
            // * 匹配掉相同字符
            ++nIndexS;
        }
        return match(s, p, nIndexS, nIndexP + 2);
    }
}
bool isMatch(string s, string p)
{
    return match(s, p, 0, 0); s
}

// 动态规划来解决问题
bool isMatch1(string s, string p) {
    int slen = s.size();
    int plen = p.size();
    vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= slen; ++i) {
        for (int j = 1; j <= plen; ++j) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            }
            else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
    }
    return dp[slen][plen];
}

int main()
{
    cout << isMatch("1988", "88") << endl;
    cout << isMatch("1988", "89") << endl;
    cout << isMatch("1988", "98") << endl;
    cout << isMatch1("1988", "88") << endl;
    cout << isMatch1("1988", "89") << endl;
    cout << isMatch1("1988", "98") << endl;
    getchar();
    return 0;
}
