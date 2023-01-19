/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
 public:
  int nearestExit(vector<vector<char>>& M, vector<int>& E) {
    int m = M.size();
    int n = M[0].size();

    auto is_exit = [&](int i, int j) -> bool {
      if (M[i][j] == '+') return false;
      if (i == E[0] && j == E[1]) return false;

      return (i == 0) || (j == 0) || (i == m - 1) || (j == n - 1);
    };

    vector<pair<int, int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set<int> visited;
    queue<vector<int>> q; // i, j, steps
    q.push({E[0], E[1], 0});

    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        vector<int> v = q.front();
        q.pop();
        int i = v[0];
        int j = v[1];
        int step = v[2];

        if (visited.count((i << 16) + j)) continue;

        if (is_exit(i, j)) {
          return step;
        }

        for (auto& d : drs) {
          int ni = i + d.first;
          int nj = j + d.second;
          if (0 <= ni && ni < m && 0 <= nj && nj < n && M[ni][nj] == '.')
            q.push({ni, nj, step + 1});
        }

        visited.insert((i << 16) + j);
      }
    }

    return -1;
  }
};
// @lc code=end
