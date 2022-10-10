/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> memo(m + 1, vector<int>(n, -1));

    return dp(s, p, 0, 0, memo);
  }

 private:
  bool dp(const string& s, const string& p, int i, int j,
          vector<vector<int>>& memo) {
    if(j == p.size()) return i == s.size();

    if (memo[i][j] != -1) return static_cast<bool>(memo[i][j]);

    bool res = false;

    if (p[j] == '*') {
      res = (i < s.size() && dp(s, p, i + 1, j, memo)) || dp(s, p, i, j + 1, memo);
    } else {
      bool match = i < s.size() && (s[i] == p[j] || p[j] == '?');

      res = match && dp(s, p, i + 1, j + 1, memo);
    }


    return memo[i][j] = static_cast<int>(res);
  }
};
// @lc code=end

