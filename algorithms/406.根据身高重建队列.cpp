/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {
            return (p1[0] > p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> ret;
        for (vector<int> p : people) {
            ret.insert(ret.begin() + p[1], p);
        }

        return ret;
    }
};

