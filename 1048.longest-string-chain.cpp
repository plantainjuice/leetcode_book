/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    auto cmp = [](const string& word1, const string& word2) -> bool {
      return word1.size() < word2.size();
    };

    // sort by length
    sort(words.begin(), words.end(), cmp);

    int max_chain = 1;
    int n = words.size();
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (isPredecessor(words[j], words[i]))
          dp[i] = max(dp[i], dp[j] + 1);
      }
      max_chain = max(max_chain, dp[i]);
    }

    return max_chain;
  }

  bool isPredecessor(const string& word1, const string& word2) {
    if (word1.size() + 1 != word2.size()) return false;

    int i = 0, j = 0;
    while (i < word1.size() && j < word2.size()) {
      if (word1[i] == word2[j]) {
        ++i;
        ++j;
        continue;
      }

      ++j;
    }

    if (i == word1.size()) return true;

    return false;
  }
};
// @lc code=end

