/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    int m = image.size();
    int n = image[0].size();

    vector<pair<int, int>> drs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    function<void(int, int, int)> dfs = [&](int i, int j, int pixel) -> void {
      if (i < 0 || i >= m || j < 0 || j >= n) return;

      // has been visited || not island
      if (image[i][j] != pixel || image[i][j] == -1) return;

      image[i][j] = -1;

      for (auto dr : drs) {
        int dx = dr.first;
        int dy = dr.second;
        dfs(i + dx, j + dy, pixel);
      }
    };

    dfs(sr, sc, image[sr][sc]);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (image[i][j] == -1) image[i][j] = color;
      }
    }

    return image;
  }
};
// @lc code=end

