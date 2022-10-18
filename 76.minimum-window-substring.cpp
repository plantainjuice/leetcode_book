/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    map<char, int> s_feq;
    map<char, int> t_feq;
    for (char c : t) ++t_feq[c];

    string ans = "";
    int cnt = 0;
    int min_w = s.size() + 1;
    int l = 0, r = 0;

    while (l < s.size()) {
      // [l, r)
      if (r < s.size() && cnt < t.size()) {
        char c = s[r];
        ++s_feq[c];

        if (s_feq[c] <= t_feq[c])
          ++cnt;

        ++r;
      } else {
        if (cnt == t.size() && r - l < min_w) {
          min_w = r - l;
          ans = s.substr(l, r - l);
        }

        char c = s[l];
        if (s_feq[c] == t_feq[c])
          --cnt;

        --s_feq[c];
        ++l;
      }
    }

    return ans;
  }
};
// @lc code=end

