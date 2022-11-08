/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
class Solution {
 public:
  int minDeletionSize(vector<string>& S) {
    int m = S.size();
    int n = S[0].size();

    vector<int> dp(n, 1);

    // LIS
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < m; ++k) {
          if (S[k][i] < S[k][j]) break;

          if (k == m - 1) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
      }
    }

    return n - *max_element(dp.begin(), dp.end());
  }
};
// @lc code=end
