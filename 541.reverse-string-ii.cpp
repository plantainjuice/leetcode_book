/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();

    int i = 0;
    while (true) {
      int from = i * k;

      if (from + k <= n)
        reverse_str(s, from, from + k);
      else {
        reverse_str(s, from, n);
        break;
      }

      i += 2;
    }

    return s;
  }

private:
  // [from, to)
  void reverse_str(string& s, int from, int to) {
    int mid = (to - from) / 2 + from;
    for(int i = from; i < mid; i++) {
      swap(s[i], s[from + to - i - 1]);
    }
  }
};
// @lc code=end

