/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i < 0 || i >= m || j < 0 || j >= n) return 0;

      // has been visited || not island
      if (grid[i][j] == 0) return 0;

      grid[i][j] = 0;

      int sum = 1;
      for (auto dr : drs) {
        int dx = dr.first;
        int dy = dr.second;
        sum += dfs(i + dx, j + dy);
      }

      return sum;
    };

    int max_area = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          max_area = max(max_area, dfs(i, j));
        }
      }
    }

    return max_area;
  }
};
// @lc code=end

