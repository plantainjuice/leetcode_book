/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() == 1) return 0;

    int hold[2], sell[2];
    hold[0] = -prices[0];
    sell[0] = 0;

    for (int i = 1; i < prices.size(); ++i) {
      hold[1] = max(hold[0], sell[0] - prices[i]);
      sell[1] = max(sell[0], hold[0] + prices[i] - fee);

      hold[0] = hold[1];
      sell[0] = sell[1];
    }

    return max(hold[1], sell[1]);
  }
};
// @lc code=end

