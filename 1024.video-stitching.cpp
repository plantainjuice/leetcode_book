/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    constexpr int kInf = 101;
    vector<vector<int>> dp(T + 1, vector<int>(T + 1, kInf));

    for (vector<int>& c : clips) {
      int s = c[0];
      int e = c[1];

      for (int l = 1; l <= T; ++l) {
        for (int i = 0; i <= T - l; ++i) {
          int j = i + l;

          if (i > e || j < s) continue;

          if (s <= i && j <= e)
            dp[i][j] = 1;
          else if (e >= j)
            dp[i][j] = min(dp[i][j], dp[i][s] + 1);
          else if (s <= i)
            dp[i][j] = min(dp[i][j], dp[e][j] + 1);
          else
            dp[i][j] = min(dp[i][j], dp[i][s] + 1 + dp[e][j]);
        }
      }
    }

    return dp[0][T] == kInf ? -1 : dp[0][T];
  }
};
// @lc code=end

