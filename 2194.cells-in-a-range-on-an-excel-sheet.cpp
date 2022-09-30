/*
 * @lc app=leetcode id=2194 lang=cpp
 *
 * [2194] Cells in a Range on an Excel Sheet
 */

// @lc code=start
class Solution {
 public:
  vector<string> cellsInRange(string s) {
    vector<string> res;
    for (char c = s[0]; c <= s[3]; ++c)
      for (char r = s[1]; r <= s[4]; ++r) res.push_back({c, r});
    return res;
  }
};
// @lc code=end

