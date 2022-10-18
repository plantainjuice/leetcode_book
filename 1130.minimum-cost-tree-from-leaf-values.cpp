/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> L(n, vector<int>(n));  // largest child

    for (int i = 0; i < n; ++i) {
      L[i][i] = arr[i];
      for (int j = i + 1; j < n; ++j) {
        L[i][j] = max(L[i][j - 1], arr[j]);
      }
    }

    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i + l <= n; ++i) {
        int j = i + l - 1;

        dp[i][j] = INT_MAX;
        for (int k = i; k < j; ++k) {
          dp[i][j] =
              min(dp[i][j], dp[i][k] + dp[k + 1][j] + L[i][k] * L[k + 1][j]);
        }
      }
    }

    return dp[0][n - 1];
  }
};
// @lc code=end

