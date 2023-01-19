/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    vector<pair<int, int>> dp(n);

    dp[0] = {INT_MIN, values[0]};
    for (int i = 1; i < n; ++i) {
      int l = max(values[i] - i + dp[i - 1].second, dp[i - 1].first);
      int r = max(values[i] + i, dp[i - 1].second);
      dp[i] = {l, r};
    }

    return dp[n - 1].first;
  }
};
// @lc code=end

