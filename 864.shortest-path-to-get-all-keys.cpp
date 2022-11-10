/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // BFS init
    queue<vector<int>> q;  // <x, y, key>
    vector<vector<vector<bool>>> visited(
        m,
        vector<vector<bool>>(n, vector<bool>(64, false)));  // at most 0b111111

    // 1. find start-point & locks
    int K = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char c = grid[i][j];

        // start-point
        if (c == '@') q.push({i, j, 0});

        // lock
        if ('A' <= c && c <= 'F') ++K;
      }
    }

    // 2. BFS
    int path = 0;
    vector<pair<int, int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        vector<int> it = q.front();
        q.pop();
        int i = it[0], j = it[1], carry = it[2];

        if (carry == (1 << K) - 1) return path;

        for (pair<int, int>& dr : drs) {
          int x = i + dr.first;
          int y = j + dr.second;
          int k = carry;

          if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#')
            continue;

          if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
            k = carry | (1 << (grid[x][y] - 'a'));  // update hold keys
          } else if (grid[x][y] >= 'A' && grid[x][y] <= 'F') {
            if (!(carry & (1 << (grid[x][y] - 'A')))) continue;
          }

          if (!visited[x][y][k]) {
            visited[x][y][k] = true;
            q.push({x, y, k});
          }
        }
      }

      ++path;
    }

    return -1;
  }
};
// @lc code=end

