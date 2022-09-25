/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int max_count = 1;
    vector<int> dp(nums.size(), 1);
    vector<int> count(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            count[i] = count[j];
          } else if (dp[j] + 1 == dp[i]) {
            count[i] += count[j];
          }
        }
        if (dp[i] > max_count) max_count = dp[i];
      }
    }

    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (max_count == dp[i]) result += count[i];
    }
    return result;
  }
};
// @lc code=end

