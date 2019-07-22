/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前K个高频元素
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (size_t i = 0; i < nums.size(); i++) {
            map<int, int>::iterator iterFind = mp.find(nums[i]);
            if (iterFind != mp.end()) {
                iterFind->second = iterFind->second + 1;
            } else {
                mp.insert(pair<int, int>(nums[i], 1));
            }
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : mp) {
            pq.push(std::make_pair(it.second, it.first));
        }

        vector<int> vecRet = {};
        for (size_t i = 0; i < k; i++) {
            vecRet.push_back(pq.top().second);
            pq.pop();
        }

        return vecRet;
    }

};

