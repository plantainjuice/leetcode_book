/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
 public:
//   int minDistance(string word1, string word2) {
  int minDistance(const string& word1, const string& word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) dp[i][0] = i;
    for (int j = 1; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
          continue;
        }

        int t1 = dp[i - 1][j - 1] + 1;  // substitute word1[i-1] & word2[j-1]
        int t2 = dp[i - 1][j] + 1;      // delete or add
        int t3 = dp[i][j - 1] + 1;      // add or delete

        dp[i][j] = min(t1, min(t2, t3));
      }
    }

    return dp[m][n];
  }
};
// @lc code=end

