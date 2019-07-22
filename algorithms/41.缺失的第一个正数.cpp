/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (size_t i = 0; i < size;) {
            if (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            } else {
                i++;
            }
        }

        for (size_t i = 0; i < size; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size + 1;
    }
};

