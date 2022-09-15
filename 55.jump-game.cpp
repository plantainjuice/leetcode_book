/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.size() <= 1) return true;

    int most = 0;
    for (int i = 0; i <= most; ++i) {
      most = max(most, nums[i] + i);
      if (most >= nums.size() - 1) return true;
    }

    return false;
  }
};
// @lc code=end

