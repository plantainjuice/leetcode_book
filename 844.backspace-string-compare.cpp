/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
 public:
  // bool backspaceCompare(string s, string t) {
  bool backspaceCompare(const string& s, const string& t) {
    int i = s.size() - 1;
    int j = t.size() - 1;

    int skip_i = 0;
    int skip_j = 0;
    while (true) {
      while (i >= 0) {
        if (s[i] == '#')
          ++skip_i;
        else {
          if (skip_i > 0)
            --skip_i;
          else
            break;
        }
        --i;
      }

      while (j >= 0) {
        if (t[j] == '#')
          ++skip_j;
        else {
          if (skip_j > 0)
            --skip_j;
          else
            break;
        }
        --j;
      }

      if (i < 0 || j < 0) break;
      if (s[i] != t[j]) return false;
      --i;
      --j;
    }

    return (i == -1) && (j == -1);
  }
};
// @lc code=end

