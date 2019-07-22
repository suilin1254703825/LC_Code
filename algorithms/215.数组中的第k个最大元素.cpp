/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
class Solution {
public:
    // 3.快速选择排序
    void swapValue(vector<int>& nums, int a, int b) {
        int j = nums[a];
        nums[a] = nums[b];
        nums[b] = j;
    }

    int partition(vector<int>& nums, int l, int r) {
        int i = l;
        int povit = nums[r];

        for (size_t j = l; j < r; j++) {
            if (nums[j] < povit) {
                swapValue(nums, j, i);
                ++i;
            }
        }

        swapValue(nums, i, r);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        k = nums.size() - k;
        int val = l;
        while (l <= r) {
            val = partition(nums, l, r);
            if (val > k) {
                r = val - 1;
            } else if (val < k) {
                l = val + 1;
            } else {
                break;
            }
        }
        return nums[val];
    }
};

