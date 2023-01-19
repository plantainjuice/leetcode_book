/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 */

// @lc code=start
class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double h = hour * 30;
    double m = minutes * 6;

    h += m * 30.0 / 360.0;

    double ans = max(h, m) - min(h, m);

    if (ans < 180) return ans;

    return 360.0 - ans;
  }
};
// @lc code=end
