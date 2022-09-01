/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
#include <string>

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    auto check_share = [](const string& w1, const string& w2) -> bool {
      int cnt[26] = {0};
      for (const char c : w1) ++cnt[c - 'a'];

      for (const char c : w2)
        if (cnt[c - 'a']) return true;

      return false;
    };

    size_t ans = 0;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        const string& w1 = words[i];
        const string& w2 = words[j];

        size_t p = w1.size() * w2.size();

        if (p <= ans) continue;

        if (check_share(w1, w2)) continue;

        ans = max(ans, p);
      }
    }

    return ans;
  }
};
// @lc code=end

