/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0, j = 0;  // word pointer
    int m = 0, n = 0;  // char pointer

    while (i < word1.size() && j < word2.size()) {
      if (word1[i][m++] != word2[j][n++]) return false;

      if (m == word1[i].size()) {
        ++i;
        m = 0;
      }

      if (n == word2[j].size()) {
        ++j;
        n = 0;
      }
    }

    return i == word1.size() && j == word2.size();
  }
};
// @lc code=end

