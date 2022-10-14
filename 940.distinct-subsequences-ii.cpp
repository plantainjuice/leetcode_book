/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
class Solution {
  // https://leetcode.com/problems/distinct-subsequences-ii/discuss/192095/C%2B%2B-O(n)-or-O-(n)-Geeks4Geeks-improved-to-O(n)-or-O(1)
 public:
  int distinctSubseqII(string S) {
    constexpr int MOD = 1e9 + 7;
    vector<int> pos(26, 0);
    vector<int> dp(S.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= S.size(); ++i) {
      size_t idx = S[i - 1] - 'a';

      // has been appeared before
      if (pos[idx] != 0) dp[i] = MOD - dp[pos[idx] - 1];

      dp[i] = dp[i] + 2 * dp[i - 1] % MOD;
      dp[i] = dp[i] % MOD;
      pos[idx] = i;
    }

    return dp[S.size()] - 1;
  }
};
// @lc code=end

