/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        string w = s.substr(j, i - j);

        if (wordSet.find(w) == wordSet.end()) continue;

        if (dp[j] == false) continue;

        dp[i] = true;
        break;
      }
    }

    return dp[n];
  }
};
// @lc code=end

