/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    auto is_magic_sqr = [&](int i, int j) -> bool {
      if (i + 2 >= m || j + 2 >= n) return false;

      int col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
      int col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
      int col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
      int row1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
      int row2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
      int row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
      int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
      int diag2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
      if ((col1 == col2) && (col1 == col3) && (col1 == row1) &&
          (col1 == row2) && (col1 == row3) && (col1 == diag1) &&
          (col1 == diag2)) {
        set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int r = 0; r < 3; r++) {
          for (int c = 0; c < 3; c++) {
            s.erase(grid[i + r][j + c]);
          }
        }
        return s.empty();
      }

      return false;
    };

    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (is_magic_sqr(i, j)) ++ans;

    return ans;
  }
};
// @lc code=end
