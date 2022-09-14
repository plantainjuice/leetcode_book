/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
public:
  int maxProfit(vector<int>& prices) {
    const int n = prices.size();

    if (n == 1) return 0;

    // hold, sell, cooldown
    int s0[2], s1[2], s2[2];
    s0[0] = -prices[0];
    s1[0] = 0;
    s2[0] = 0;

    for (int i = 1; i < n; ++i) {
      s0[1] = max(s0[0], s1[0] - prices[i]);
      s1[1] = max(s1[0], s2[0]);
      s2[1] = s0[0] + prices[i];

      s0[0] = s0[1];
      s1[0] = s1[1];
      s2[0] = s2[1];
    }

    return max(s1[1], s2[1]);
  }

  int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    // s0: rest, s1: sell, s2: cooldown
    vector<int> s0(n, 0);
    vector<int> s1(n, 0);
    vector<int> s2(n, 0);

    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;

    for (int i = 1; i < n; ++i) {
      s0[i] = max(s0[i - 1], s2[i - 1]);
      s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
      s2[i] = s1[i - 1] + prices[i];
    }

    return max(s0[n - 1], s2[n - 1]);
  }
};
// @lc code=end

