/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
 public:
  int maxSumDivThree(vector<int>& nums) {
    int n = nums.size();
    array<int, 3> dp = {0, 0, 0}; // the max sum end with 0, 1, 2 after mod by 3

    for (int i = 0; i < n; ++i) {
      int s1 = dp[0] + nums[i];
      int s2 = dp[1] + nums[i];
      int s3 = dp[2] + nums[i];

      int c1 = s1 % 3;
      int c2 = s2 % 3;
      int c3 = s3 % 3;
      dp[c1] = max(dp[c1], s1);
      dp[c2] = max(dp[c2], s2);
      dp[c3] = max(dp[c3], s3);
    }

    return dp[0];
  }
};
// @lc code=end

