/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
 public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<double>> dp(n, vector<double>(n, 0));

    auto is_valid = [&](int x, int y) -> bool {
      if (0 <= x && x < n && 0 <= y && y < n) return true;
      return false;
    };

    vector<pair<int, int>> dr = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
    };

    dp[row][column] = 1; // init
    while(k--) {
      vector<vector<double>> dp2(n, vector<double>(n, 0));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (pair<int, int>& d : dr) {
            int r = i + d.first;
            int c = j + d.second;
            if (is_valid(r, c)) {
                dp2[r][c] += dp[i][j] / 8.0;
            }
          }
        }
      }

      dp = dp2;
    }

    double ans = 0;
    for(auto& r : dp) {
      for (double c : r) {
        ans += c;
      }
    }

    return ans;
  }
};
// @lc code=end

