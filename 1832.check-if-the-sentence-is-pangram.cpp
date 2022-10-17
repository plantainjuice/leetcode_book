/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
 public:
  bool checkIfPangram(string sentence) {
    vector<bool> m(26, false);
    for (char c : sentence) m[c - 'a'] = true;

    for (bool b : m)
      if (b == false) return false;
    return true;
  }
};
// @lc code=end

