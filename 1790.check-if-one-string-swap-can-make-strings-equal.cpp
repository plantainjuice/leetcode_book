/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    vector<array<char, 2>> mis;

    for (int i = 0; i < s1.size() && mis.size() < 3; ++i) {
      if (s1[i] != s2[i]) {
        if (mis.size() == 0) {
          mis.push_back({s1[i], s2[i]});
        } else {
          mis.push_back({s2[i], s1[i]});
        }
      }
    }

    return mis.empty() || (mis.size() == 2 && mis[0] == mis[1]);
  }
};
// @lc code=end

