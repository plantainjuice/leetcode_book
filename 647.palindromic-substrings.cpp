/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
 // int countSubstrings(string s) {
 int countSubstrings(const string& s) {
   int n = s.size();
   vector<vector<bool>> dp(n, vector<bool>(n, false));

   int ans = 0;
   for (int i = n - 1; i >= 0; --i) {
     for (int j = i; j < n; ++j) {
       if (s[i] != s[j]) continue;

       if (j - i <= 1) {
         dp[i][j] = true;
         ++ans;
         continue;
       }

       if (dp[i + 1][j - 1]) {
         dp[i][j] = true;
         ++ans;
         continue;
       }
     }
   }

   return ans;
 }
};
// @lc code=end

