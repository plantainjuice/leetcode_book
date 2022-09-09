/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
 int coinChange(vector<int>& coins, int amount) {
   vector<long> dp(amount + 1, INT_MAX);
   dp[0] = 0;

   for (int i = 1; i <= amount; ++i) {
     for (int coin : coins) {
       if (i - coin < 0) continue;

       dp[i] = min(dp[i], dp[i - coin] + 1);
     }
   }

   return dp[amount] == INT_MAX? -1 : dp[amount];
 }
};
// @lc code=end

