/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
bool isValid(string s) {
    if (s.size() % 2 == 1) return false;
    if (s.empty()) return true;

    string stTemp;
    stTemp.push_back(s[0]);

    for (size_t i = 1; i < s.size(); i++) {
        int k = stTemp.size() - 1;
        if (stTemp[k] == '(' && s[i] == ')') stTemp.pop_back();
        else if (stTemp[k] == '[' && s[i] == ']') stTemp.pop_back();
        else if (stTemp[k] == '{' && s[i] == '}') stTemp.pop_back();
        else stTemp.push_back(s[i]);
    }
	return stTemp.empty();
}
};

