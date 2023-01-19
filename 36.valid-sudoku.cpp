/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& B) {
    bool find = false;

    auto is_valid = [&](int x, int y, char c) -> bool {
      for (int i = 0; i < 9; ++i)
        if (B[x][i] == c && y != i) return false;

      for (int i = 0; i < 9; ++i)
        if (B[i][y] == c && x != i ) return false;

      int xblock = (x / 3) * 3;
      int yblock = (y / 3) * 3;
      for (int i = xblock; i < xblock + 3; ++i)
        for (int j = yblock; j < yblock + 3; ++j)
          if (B[i][j] == c && x != i && y != j) return false;

      return true;
    };

    for (int i = 0; i < 81; ++i) {
      int x = i / 9;
      int y = i % 9;
      char c = B[x][y];
      if (c != '.' && !is_valid(x, y, c)) return false;
    }

    return true;

    /*
    function<void(int)> backtrace = [&](int index) -> void {
      if (index == 81) {
        find = true;
        return;
      }

      int x = index / 9;
      int y = index % 9;

      if (B[x][y] != '.') return backtrace(index + 1);

      for (char i = '1'; i <= '9'; ++i) {
        if (!is_valid(x, y, i)) continue;

        B[x][y] = i;
        backtrace(index + 1);
        B[x][y] = '.';
      }
    };

    return find;
    */
  }
};
// @lc code=end
