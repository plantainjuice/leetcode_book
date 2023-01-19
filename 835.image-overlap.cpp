/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
 public:
  int largestOverlap(vector<vector<int>>& M1, vector<vector<int>>& M2) {
    int n = M1.size();

    auto overlap = [&](int dx, int dy) -> int {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          int x = i + dx;
          int y = j + dy;
          if (0 <= x && x < n && 0 <= y && y < n) {
            if (M1[x][y] == 1 && M2[i][j] == 1) ++cnt;
          }
        }
      }

      return cnt;
    };

    int ans = 0;
    for (int i = -n; i <= n; ++i) {
      for (int j = -n; j <= n; ++j) {
        ans = max(ans, overlap(i, j));
      }
    }

    return ans;
  }
};
// @lc code=end

