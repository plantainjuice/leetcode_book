/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
 // int minimumDeleteSum(string s1, string s2) {
 int minimumDeleteSum(const string& s1, const string& s2) {
   int n1 = s1.size();
   int n2 = s2.size();

   vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

   for (int i = 1; i <= n1; ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
   for (int j = 1; j <= n2; ++j) dp[0][j] = dp[0][j - 1] + s2[j - 1];

   for (int i = 1; i <= n1; ++i) {
     for (int j = 1; j <= n2; ++j) {
       if (s1[i - 1] == s2[j - 1]) {
         dp[i][j] = dp[i - 1][j - 1];
         continue;
       }

    //    int c1 = dp[i - 1][j - 1] + min(s1[i - 1], s2[j - 1]);
       int c2 = dp[i - 1][j] + s1[i - 1];
       int c3 = dp[i][j - 1] + s2[j - 1];

    //    dp[i][j] = min(c1, min(c2, c3));
       dp[i][j] = min(c2, c3);
     }
   }

   return dp[n1][n2];
 }
};
// @lc code=end

