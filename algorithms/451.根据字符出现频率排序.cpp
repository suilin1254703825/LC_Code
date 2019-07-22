/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (size_t i = 0; i < s.size(); i++) {
            map<char, int>::iterator iterFind = mp.find(s[i]);
            if (iterFind != mp.end()) {
                iterFind->second = iterFind->second + 1;
            } else {
                mp.insert(pair<char, int>(s[i], 1));
            }
        }
        string strRet;

        priority_queue<pair<char, int>> pq;
        for (auto it : mp) {
            pq.push(std::make_pair(it.second, it.first));
        }

        while (!pq.empty()) {
            string strTemp = "";
            auto pair_value = pq.top();
            for (size_t i = 0; i < pair_value.first; i++) {
                strTemp += pair_value.second;
            }
            strRet += strTemp;
            pq.pop();
        }

        return strRet;
    }
};

