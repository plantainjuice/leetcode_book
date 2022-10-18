/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
 public:
  string countAndSay(int n) {
    string s = "1";
    while (--n) s = countAndSay(s);

    return s;
  }

 private:
  string countAndSay(string s) {
    string res = "";
    int n = s.size();
    int l = 0, h = 0;

    while (h < n) {
      if (s[l] == s[h]) {
        ++h;
      } else {
        res += to_string(h - l) + s[l];
        l = h;
      }
    }

    res += to_string(h - l) + s[l];

    return res;
  }
};
// @lc code=end

