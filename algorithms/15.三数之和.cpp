/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vecRet;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (size_t i = 0; i < size; ++i) {
        int p = i + 1;
        int q = size - 1;
        int target = 0 - nums[i];
        while (p < q) {
            int sum = nums[p] + nums[q];
            if (sum > target) --q;
            else if (sum < target) ++p;
            else {
                vector<int> vecTemp(3, 0);
                vecTemp[0] = nums[i];
                vecTemp[1] = nums[p];
                vecTemp[2] = nums[q];
                vecRet.push_back(vecTemp);
                while (p < q && nums[p] == vecTemp[1]) ++p;
                while (p < q && nums[q] == vecTemp[2]) --q;
            }
        }

        while (i + 1 < size && nums[i + 1] == nums[i]) ++i;
    }

    return vecRet;
}
};
