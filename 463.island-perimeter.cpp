/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int ans = 0;

    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          for (vector<int>& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
                grid[x][y] == 0)
              ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// @lc code=end

