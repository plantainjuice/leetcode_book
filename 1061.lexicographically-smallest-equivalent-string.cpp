/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    // classic union set problem
    vector<char> unionSet(26);
    iota(unionSet.begin(), unionSet.end(), 'a');

    function<char(char)> _find = [&](char c) -> char {
      if (c == unionSet[c - 'a']) return c;
      return unionSet[c - 'a'] = _find(unionSet[c - 'a']);
    };

    function<void(char, char)> _union = [&](char c1, char c2) -> void {
      c1 = _find(c1);
      c2 = _find(c2);

      if (c1 != c2) unionSet[max(c1, c2) - 'a'] = min(c1, c2);
    };

    for (int i = 0; i < s1.size(); ++i) _union(s1[i], s2[i]);

    for (int i = 0; i < baseStr.size(); ++i) baseStr[i] = _find(baseStr[i]);

    return baseStr;
  }
};
// @lc code=end
