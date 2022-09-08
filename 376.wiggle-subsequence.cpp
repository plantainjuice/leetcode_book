/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size(), peak = 1, valley = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1])
        valley = peak + 1;
      else if (nums[i] < nums[i - 1])
        peak = valley + 1;
    }

    return max(peak, valley);
  }
};
// @lc code=end

