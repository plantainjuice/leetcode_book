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
    int l = 0;
    int r = 0;

    for (char c : s) {
      if (c == 'L')
        ++l;
      else
        ++r;

      if (l == r) {
        ++ans;
      }
    }

    return ans;
  }
};
// @lc code=end

