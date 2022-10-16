/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        constexpr int MOD = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1; // init

        vector<pair<int, int>> dr = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };

        int res = 0;
        while(maxMove--) {
          vector<vector<int>> dp2(m, vector<int>(n, 0));

          for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
              // move
              for (pair<int, int>& d : dr) {
                int x = i + d.first;
                int y = j + d.second;
                // is valid
                if (0 <= x && x < m && 0 <= y && y < n) {
                  dp2[x][y] = (dp2[x][y] + dp[i][j]) % MOD;
                } else {
                  res = (res + dp[i][j] % MOD) % MOD;
                }
              }
            }
          }

          dp = dp2;
        }

        return res;
    }
};
// @lc code=end

