/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;

    auto cmp = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
    sort(points.begin(), points.end(), cmp);

    int ans = 1;
    for (int i = 1; i < points.size(); ++i) {
      // no intersection
      if (points[i - 1][1] < points[i][0])
        ans++;
      else
        points[i][1] = min(points[i - 1][1], points[i][1]);
    }

    return ans;
  }
};
// @lc code=end

