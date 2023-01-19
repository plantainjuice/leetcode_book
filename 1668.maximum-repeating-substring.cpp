/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

// @lc code=start
class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int cnt = 0;
    string tmp = word;

    while (sequence.find(tmp) != string::npos) {
      tmp += word;
      cnt++;
    }

    return cnt;
  }
};
// @lc code=end

