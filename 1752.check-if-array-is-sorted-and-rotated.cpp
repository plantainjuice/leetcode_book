/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
 public:
  bool check(vector<int>& nums) {
    int flip_cnt = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] >= nums[i - 1]) continue;

      ++flip_cnt;

      // stop early
      if(flip_cnt > 1) return false;
    }

    return flip_cnt == 0 || flip_cnt == 1 && (nums[0] >= nums[nums.size() - 1]);
  }
};
// @lc code=end
