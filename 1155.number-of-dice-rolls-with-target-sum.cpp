/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    constexpr int MOD = 1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i <= target && i <= k; ++i) dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= target; j++)
        for (int d = 1; d <= k && d < j; d++) {
          dp[i][j] += dp[i - 1][j - d];
          dp[i][j] %= MOD;
        }

    return dp[n][target];
  }
};
// @lc code=end
