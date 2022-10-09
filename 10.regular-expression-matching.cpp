/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    memo_ = vector<vector<int>>(m + 1, vector<int>(n, -1));

    return dp(s, p, 0, 0);
  }

 private:
  // -1: unknown; 0: false; 1: true;
  vector<vector<int>> memo_;

  bool dp(const string& s, const string& p, int i, int j) {
    if (j == p.size()) return i == s.size();

    // has been calculated
    if(memo_[i][j] != -1) return static_cast<bool>(memo_[i][j]);

    bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

    bool res = false;

    if (j + 1 < p.length() && p[j + 1] == '*') {
      res = (dp(s, p, i, j + 2) || (first_match && dp(s, p, i + 1, j)));
    } else {
      res = (first_match && dp(s, p, i + 1, j + 1));
    }

    return memo_[i][j] = int(res);
  }
};
// @lc code=end

