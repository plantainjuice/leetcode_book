/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    // if nums size is less than 3 return false
    if (nums.size() < 3) return 0;

    int cnt = 0, diff = 0, ind = 0;
    int prev_diff = nums[1] - nums[0];

    for(int i = 2; i < nums.size(); ++i) {
      diff = nums[i] - nums[i-1];

      if (diff == prev_diff) {
        ++ind;
      } else {
        prev_diff = diff;
        ind = 0;
      }

      cnt += ind;
    }

    return cnt;
  }
};
// @lc code=end

