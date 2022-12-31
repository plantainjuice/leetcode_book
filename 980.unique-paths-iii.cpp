/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 1. find start & count non-obstacle
    int empty = 0;
    pair<int, int> start;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0 || grid[i][j] == 2)
          ++empty;
        else if (grid[i][j] == 1)
          start = {i, j};
      }
    }

    // 2. dfs
    int paths = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    function<void(int, int, int)> dfs = [&](int i, int j, int walk) -> void {
      if (i < 0 || i >= m || j < 0 || j >= n) return;

      // has walked or obstacle
      if (grid[i][j] == -1) return;

      if (grid[i][j] == 2) {
        if (walk == empty) ++paths;

        return;
      }

      // mark
      grid[i][j] = -1;

      for (auto dr : directions) dfs(i + dr.first, j + dr.second, walk + 1);

      // clear mark
      grid[i][j] = 0;
    };

    dfs(start.first, start.second, 0);

    return paths;
  }
};
// @lc code=end
