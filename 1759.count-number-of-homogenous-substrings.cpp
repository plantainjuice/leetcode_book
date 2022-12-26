/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
 public:
  int countHomogenous(string s) {
    constexpr int MOD = 1e9 + 7;

    long sum = 0;
    char last_c = ' ';
    int cur_len = 0;

    for (char c : s) {
      if (last_c == c)
        ++cur_len;
      else
        cur_len = 1;

      sum += cur_len;
      sum %= MOD;

      last_c = c;
    }

    return sum;
  }
};