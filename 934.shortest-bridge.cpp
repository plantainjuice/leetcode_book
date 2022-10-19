/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pair<int, int>> q;
    function<void(int, int)> dfs;
    dfs = [&](int i, int j) -> void {
      if (0 > i || i >= n || 0 > j || j >= n) return;

      if (grid[i][j] == -1) return;

      if (grid[i][j] == 0) {
          grid[i][j] = -1;
          q.push({i, j});
          return;
      }

      grid[i][j] = -1;

      for (auto& d : dr) {
        int _i = i + d.first;
        int _j = j + d.second;
        dfs(_i, _j);
      }
    };

    // mark
    bool find = false;
    for (int i = 0; i < n && !find; ++i)
      for (int j = 0; j < n && !find; ++j)
        if (grid[i][j] == 1) {
          dfs(i, j);
          find = true;
        }

    int min_l = INT_MAX;
    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        pair<int, int> p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        for (auto& d : dr) {
          int _i = i + d.first;
          int _j = j + d.second;

          if (0 <= _i && _i < n && 0 <= _j && _j < n) {
            if (grid[_i][_j] == 1) {
              min_l = min(min_l, -grid[i][j]);
              continue;
            } else if (grid[_i][_j] == 0) {
              q.push({_i, _j});
              grid[_i][_j] = grid[i][j] - 1;
            }
            grid[_i][_j] = max(grid[_i][_j], grid[i][j] - 1);
          }
        }
      }
    }

    return min_l;
  }
};

// @lc code=end

