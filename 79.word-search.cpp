/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    auto is_valid = [&](int x, int y) -> bool {
      if (0 <= x && x < m && 0 <= y && y < n) return true;
      return false;
    };

    vector<pair<int, int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    function<bool(int, int, int)> dfs = [&](int x, int y, int index) -> bool {
      if (index == word.size()) return true;

      if (!is_valid(x, y)) return false;

      if (visited[x][y]) return false;

      if (board[x][y] != word[index]) return false;

      for (auto dr : drs) {
        int nx = x + dr.first;
        int ny = y + dr.second;

        visited[x][y] = true;
        if (dfs(nx, ny, index + 1)) return true;
        visited[x][y] = false;
      }

      return false;
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(i, j, 0)) return true;
      }
    }

    return false;
  }
};
// @lc code=end
