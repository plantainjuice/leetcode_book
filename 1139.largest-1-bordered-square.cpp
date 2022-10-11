/*
 * @lc app=leetcode id=1139 lang=cpp
 *
 * [1139] Largest 1-Bordered Square
 */

// @lc code=start
class Solution {
 public:
  int largest1BorderedSquare(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> hor(m, vector<int>(n));  // horizontal
    vector<vector<int>> ver(m, vector<int>(n));  // vertical

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          hor[i][j] = i == 0 ? 1 : hor[i - 1][j] + 1;
          ver[i][j] = j == 0 ? 1 : ver[i][j - 1] + 1;
        }
      }
    }

    int max = 0;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int small = min(hor[i][j], ver[i][j]);

        while (small > max) {
          if (ver[i - small + 1][j] >= small && hor[i][j - small + 1] >= small) {
            max = small;
          }
          small--;
        }
      }
    }

    return max * max;
  }
};
// @lc code=end

