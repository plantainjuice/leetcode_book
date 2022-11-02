/*
 * @lc app=leetcode id=1620 lang=cpp
 *
 * [1620] Coordinate With Maximum Network Quality
 */

// @lc code=start
class Solution {
 public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    vector<int> ans = {0, 0};

    int max_sig = 0;
    for (int x = 0; x < 51; ++x) {
      for (int y = 0; y < 51; ++y) {
        int sig = 0;
        for (auto t : towers) {
          int dx = t[0] - x;
          int dy = t[1] - y;
          int d2 = dx * dx + dy * dy;
          int q = t[2];

          if (d2 <= radius * radius)
            sig += q / (1 + sqrt(d2));
        }

        if (sig > max_sig) {
          max_sig = sig;
          ans = {x, y};
        }
      }
    }

    return ans;
  }
};
// @lc code=end

