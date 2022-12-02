/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    vector<int> r1(26);
    vector<int> r2(26);

    for (int i = 0; i < word1.size(); ++i) {
      char c1 = word1[i];
      char c2 = word2[i];
      ++r1[c1 - 'a'];
      ++r2[c2 - 'a'];
    }

    // check occurence
    for (int i = 0; i < 26; ++i) {
        if(r1[i] == 0 && r2[i] != 0) return false;
        if(r1[i] != 0 && r2[i] == 0) return false;
    }

    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end());

    return r1 == r2;
  }
};
// @lc code=end
