/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iIndex = m - 1;
        int jIndex = n - 1;
        int mergeIndex = m + n - 1;

        while (iIndex >=0 || jIndex >= 0) {
            if (iIndex < 0) {
                nums1[mergeIndex--] = nums2[jIndex--];
            } else if (jIndex < 0) {
                nums1[mergeIndex--] = nums1[iIndex--];
            } else if (nums1[iIndex] >= nums2[jIndex]) {
                nums1[mergeIndex--] = nums1[iIndex--];
            } else {
                nums1[mergeIndex--] = nums2[jIndex--];
            }
        }
    }
};

