/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    remove_extra_spaces(s);
    reverse(s, 0, s.size() - 1);

    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') continue;

      reverse(s, start, i - 1);
      start = i + 1;
    }

    reverse(s, start, s.size() - 1);

    return s;
  }

 private:
  // [from, to]
  void reverse(string& s, int from, int to) {
    for (int i = from, j = to; i < j; ++i, --j) {
      swap(s[i], s[j]);
    }
  }

  void remove_extra_spaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (slow != 0) s[slow++] = ' ';
        while (i < s.size() && s[i] != ' ') s[slow++] = s[i++];
      }
    }

    s.resize(slow);
  }
};
// @lc code=end

