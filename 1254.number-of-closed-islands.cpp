/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    int color = -1;
    int m = grid.size();
    int n = grid[0].size();

    int closed_num = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          bool closed = dfs(grid, i, j, color--);
          if (closed) closed_num++;
        }
      }
    }

    return closed_num;
  }

 private:
  bool dfs(vector<vector<int>>& grid, int x, int y, int color) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;

    if (grid[x][y] == 0) {
      grid[x][y] = color;

      bool b1 = dfs(grid, x + 1, y, color);
      bool b2 = dfs(grid, x - 1, y, color);
      bool b3 = dfs(grid, x, y + 1, color);
      bool b4 = dfs(grid, x, y - 1, color);

      return b1 && b2 && b3 && b4;
    }

    return true;
  }
};
// @lc code=end

