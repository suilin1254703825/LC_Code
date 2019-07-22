/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = -1;
        int j = s.length();

        while (++i < --j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            }
        }
        return true;
    }

};

