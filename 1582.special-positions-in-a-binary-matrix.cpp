/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    auto is_special = [&](int x, int y) -> bool {
      if (mat[x][y] != 1) return false;

      for (int i = 0; i < m; ++i) {
        if (i == x) continue;
        if (mat[i][y] == 1) return false;
      }

      for (int j = 0; j < n; ++j) {
        if (j == y) continue;
        if (mat[x][j] == 1) return false;
      }

      return true;
    };

    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (is_special(i, j)) ++ans;

    return ans;
  }
};
// @lc code=end
