/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      int cur_max = INT_MIN;
      for (int j = i; j > i - k && j > 0; --j) {
        cur_max = max(cur_max, arr[j - 1]);
        dp[i] = max(dp[i], dp[j - 1] + cur_max * (i - j + 1));
      }
    }

    return dp[n];
  }
};
// @lc code=end

