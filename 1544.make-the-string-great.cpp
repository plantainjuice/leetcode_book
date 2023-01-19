/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
 public:
  string makeGood(string s) {
    // stack pointer
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (p > 0 && abs(s[i] - s[p - 1]) == 32) {
        --p;
      } else {
        s[p++] = s[i];
      }
    }

    return s.substr(0, p);
  }
};
// @lc code=end

