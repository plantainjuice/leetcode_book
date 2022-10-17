/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    if (points[0] == points[1] || points[1] == points[2] ||
        points[0] == points[2])
      return false;

    int dx1 = points[0][0] - points[1][0];
    int dy1 = points[0][1] - points[1][1];
    int dx2 = points[0][0] - points[2][0];
    int dy2 = points[0][1] - points[2][1];

    return dx1 * dy2 != dx2 * dy1;
  }
};
// @lc code=end

