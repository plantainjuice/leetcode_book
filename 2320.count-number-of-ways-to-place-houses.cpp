/*
 * @lc app=leetcode id=2320 lang=cpp
 *
 * [2320] Count Number of Ways to Place Houses
 */

// @lc code=start
class Solution {
public:
 int MOD = 1e9 + 7;

 int countHousePlacements(int n) {
   vector<int> dp(n + 1, -1);
   dp[0] = 1;
   dp[1] = 2;

   // 1. only consider one side
   for (int i = 2; i <= n; ++i) {
     // no adjacent
     int place = dp[i - 2];
     int not_place = dp[i - 1];

     dp[i] = (place + not_place) % MOD;
   }

   // 2. combination
   return ((long)dp[n] * dp[n]) % MOD;
 }
};
// @lc code=end

