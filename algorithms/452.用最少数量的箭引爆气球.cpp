/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int nCount = 0;
        if (!points.size()) return nCount;

        sort(points.begin(), points.end());
        nCount = 1;
        int start = points[0][0];
        int end = points[0][1];

        for (size_t i = 1; i < points.size(); i++) {
            if (end < points[i][0]) {
                start = points[i][0];
                end = points[i][1];
                nCount++;
            } else {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
        }

        return nCount;
    }
};

