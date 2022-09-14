/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int prev_hold = -prices[0];
    int prev_sell = 0;
    int cur_hold = 0;
    int cur_sell = 0;

    for (int i = 1; i < prices.size(); ++i) {
      cur_hold = max(prev_hold, prev_sell - prices[i]);
      cur_sell = max(prev_sell, prev_hold + prices[i]);

      prev_hold = cur_hold;
      prev_sell = cur_sell;
    }

    return cur_sell;
  }
};
// @lc code=end

