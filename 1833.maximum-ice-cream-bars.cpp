/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int iceCream = 0;
    for (int cost : costs) {
      if (coins < cost) break;

      coins -= cost;
      ++iceCream;
    }

    return iceCream;
  }
};
// @lc code=end
