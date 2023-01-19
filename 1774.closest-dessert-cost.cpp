/*
 * @lc app=leetcode id=1774 lang=cpp
 *
 * [1774] Closest Dessert Cost
 */

// @lc code=start
class Solution {
 public:
  int closestCost(vector<int>& BC, vector<int>& TC, int T) {
    int m = TC.size();

    int closest = BC[0];

    function<void(int, int, int)> dp = [&](int i, int cost, int max_top) {
      if (cost >= T || i == m) {
        if (abs(cost - T) < abs(closest - T))
          closest = cost;
        else if (abs(cost - T) == abs(closest - T))
          closest = min(closest, cost);
        return;
      }

      for (int k = 0; k <= max_top; ++k) {
        dp(i + 1, cost + k * TC[i], 2);
      }
    };

    for (int base : BC) dp(0, base, 2);

    return closest;
  }
};
// @lc code=end
