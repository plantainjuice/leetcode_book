/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    vector<pair<int, string>> M = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    string ans;
    int i = 0, n = M.size();
    while (num) {
      if (num < M[i].first) {
        ++i;
      } else {
        num -= M[i].first;
        ans += M[i].second;
      }
    }

    return ans;
  }
};
// @lc code=end

