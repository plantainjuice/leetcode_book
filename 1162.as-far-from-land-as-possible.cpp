/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();

    queue<vector<int>> q;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) q.push({i, j});

    vector<vector<int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int ans = 0;
    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        auto pos = q.front();
        q.pop();

        int x = pos[0];
        int y = pos[1];

        for (const auto& dr : drs) {
          int nx = x + dr[0], ny = y + dr[1];
          if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 0) {
            grid[nx][ny] = grid[x][y] + 1;
            ans = max(ans, grid[nx][ny] - 1);
            q.push({nx, ny});
          }
        }
      }
    }

    return ans  == 0 ? -1 : ans;
  }
};
// @lc code=end

