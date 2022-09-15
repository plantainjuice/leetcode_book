/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int ans = 0;

    int i = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] >= g[i]) {
        ++i;
        ++ans;
      }

      if (i == g.size()) break;
    }

    return ans;
  }

  /*
  int findContentChildren(vector<int>& g, vector<int>& s) {
    if(g.size() == 0 || s.size() == 0) return 0;

    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    int ans = 0;

    int i = 0;
    for (int j = 0; j < g.size(); ++j) {
      if (s[i] >= g[j]) {
        ++i;
        ++ans;
      }

      if (i == s.size()) break;
    }

    return ans;
  }
  */
};
// @lc code=end

