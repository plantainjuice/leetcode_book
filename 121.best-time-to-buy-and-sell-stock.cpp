/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  // greedy
  int maxProfit(vector<int>& prices) {
    int low = prices[0], ans = 0;

    for (int p : prices) {
      ans = max(ans, p - low);
      low = min(low, p);
    }

    return ans;
  }

  // dp
  //   int maxProfit(vector<int>& prices) {
  //     int prev_hold = -prices[0];
  //     int prev_sell = 0;
  //     int cur_hold = 0;
  //     int cur_sell = 0;

  //     for (int i = 1; i < prices.size(); ++i) {
  //       cur_hold = max(prev_hold, -prices[i]);
  //       cur_sell = max(prev_sell, prev_hold + prices[i]);

  //       prev_hold = cur_hold;
  //       prev_sell = cur_sell;
  //     }

  //     return cur_sell;
  //   }
};
// @lc code=end

