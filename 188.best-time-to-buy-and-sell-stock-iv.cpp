/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();

        // k > n / 2, meaningless
        if (k > n / 2)  k = n / 2;

        vector<int> buys(k+1, INT_MIN);
        vector<int> sells(k+1, 0);

        for (int i = 0; i < n; ++i)
          for (int j = 1; j <= k; ++j) {
            buys[j] = max(buys[j], sells[j - 1] - prices[i]);
            sells[j] = max(sells[j], buys[j] + prices[i]);
          }

        return sells[k];
    }
};
// @lc code=end

