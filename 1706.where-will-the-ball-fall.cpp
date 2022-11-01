/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    auto is_valid = [&](int r, int c) -> bool {
      if (r < 0 || c < 0 || r >= m || c >= n) return false;
      return true;
    };

    function<int(int, int)> dfs = [&](int r, int c) -> int {
      if (r == m) return c;

      if (!is_valid(r, c)) return -1;

      if (grid[r][c] == 1) {
        if (is_valid(r, c + 1) && grid[r][c + 1] == 1) 
          return dfs(r + 1, c + 1);
      } else {
        if (is_valid(r, c - 1) && grid[r][c - 1] == -1)
          return dfs(r + 1, c - 1);
      }

      return -1;
    };

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) ans[i] = dfs(0, i);

    return ans;
  }
};
// @lc code=end

