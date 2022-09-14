/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    int ans = dp[0];
    for (int i = 1; i < n; ++i) {
      if(dp[i - 1] < 0) {
        dp[i] = nums[i];
      } else {
        dp[i] = dp[i - 1] + nums[i];
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// @lc code=end

