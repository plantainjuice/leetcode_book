/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
 public:
  // int balancedStringSplit(string s) {
  int balancedStringSplit(const string& s) {
    int ans = 0;
    int l_count = 0, r_count = 0;
    for (char c : s) {
      if (c == 'L') l_count++;
      else if (c == 'R') r_count++;

      if (l_count == r_count) ans++;
    }

    return ans;
  }
};
// @lc code=end

