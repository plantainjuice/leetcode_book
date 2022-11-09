/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<bool>> grid(n, vector<bool>(n, true));
    for (vector<int>& m : mines) grid[m[0]][m[1]] = false;

    vector<vector<int>> drs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(4, -1)));
    int memo[500][500][4] = {0};
    function<int(int, int, int)> dp = [&](int i, int j, int d) -> int {
      if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == false) return 0;

      if (memo[i][j][d] > 0) return memo[i][j][d];

      int di = drs[d][0];
      int dj = drs[d][1];

      return memo[i][j][d] = dp(i + di, j + dj, d) + 1;
    };

    int max_ = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int l = n;
        for (int d = 0; d < 4; d++) {
          l = min(l, dp(i, j, d));
        }
        max_ = max(max_, l);
      }
    }

    return max_;
  }
};
// @lc code=end

