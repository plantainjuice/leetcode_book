/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();

    for (int l = 1; l <= n / 2; ++l) {
      if (n % l != 0) continue;

      string sub = s.substr(0, l);

      int k = n / l;
      while (k)
        if (s.substr(k * l, l) != sub) break;

      if (k == 0) return true;
    }

    return false;
  }
};
// @lc code=end
