/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
class Solution {
public:
    string reverseVowels(string s) {
        string strVowel = "aeiouAEIOU";

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char si = s[i];
            char sj = s[j];
            if (string::npos == strVowel.find(si)) {
                s[i++] = si;
            } else if (string::npos == strVowel.find(sj)) {
                s[j--] = sj;
            } else {
                s[j--] = si;
                s[i++] = sj;
            }
        }

        return s;
    }
};

