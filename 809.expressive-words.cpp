/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
class Solution {
 public:
  int expressiveWords(string s, vector<string>& words) {
    auto is_stretchy = [&](const string& w) -> bool {
      if (w.size() > s.size()) return false;

      int i = 0, j = 0;
      while (i < s.size()) {
        if (j < w.size() && s[i] == w[j]) {
          ++i;
          ++j;
          continue;
        }

        // stretchy
        if (i >= 1 && i < s.size() - 1 && s[i - 1] == s[i] && s[i] == s[i + 1]) {
          ++i;
          continue;
        }

        // stretchy 
        if (i >= 2 && s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
          ++i;
          continue;
        }

        return false;
      }

      return i == s.size() && j == w.size();
    };

    int ans = 0;
    for (const string& w : words)
      if (is_stretchy(w)) ++ans;

    return ans;
  }
};
// @lc code=end
