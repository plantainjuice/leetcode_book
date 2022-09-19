/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;

    int ans = INT_MAX;
    int sum = 0;
    // slide window
    for (int r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum >= target) {
        ans = min(ans, (r - l + 1));
        sum -= nums[l++];
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};
// @lc code=end

