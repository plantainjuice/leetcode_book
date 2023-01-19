/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution {
 public:
  bool isIdealPermutation(vector<int>& nums) {
    int n = nums.size();

    int cmax = 0;
    for (int i = 0; i < n - 2; ++i) {
      cmax = max(cmax, nums[i]);
      if (cmax > nums[i + 2]) return false;
    }

    return true;
  }
};
// @lc code=end
