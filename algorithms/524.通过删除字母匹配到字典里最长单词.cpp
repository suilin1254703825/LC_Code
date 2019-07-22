/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
class Solution {
public:

    bool strVaild(string s, string strTarget) {
        int i = 0;
        int j = 0;
        int s1 = s.size();
        int s2 = strTarget.size();
        while (i < s1 && j < s2) {
            if (s[i] == strTarget[j]) {
                j++;
            }
            i++;
        }

        return j == s2;
    }

    string findLongestWord(string s, vector<string>& d) {
        string longestWord = "";

        // 遍历数组
        for (size_t i = 0; i < d.size(); i++) {
            string strTarget = d[i];
            int s1 = longestWord.size();
            int s2 = strTarget.size();
            // || (s1 == s2 && longestWord > strTarget)
            if (s1> s2 || (s1 == s2 && longestWord <= strTarget)) {
                continue;
            }

            if (strVaild(s, strTarget)) {
                longestWord = strTarget;
            }
        }

        return longestWord;
    }
};

