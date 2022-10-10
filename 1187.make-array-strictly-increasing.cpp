/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */

// @lc code=start
class Solution {
 public:
  int makeArrayIncreasing(vector<int>& t, vector<int>& s) {
    sort(begin(s), end(s));

    memo1_ = vector<vector<int>>(t.size(), vector<int>(s.size() + 1, MAX_VAL));
    memo2_ = vector<vector<int>>(t.size(), vector<int>(s.size() + 1, MAX_VAL));

    int res = dp(t, s, 0, 0, 2);
    return res >= MAX_VAL ? -1 : res;
  }

private:
  int MAX_VAL = 2002;
  vector<vector<int>> memo1_;
  vector<vector<int>> memo2_;

  // op1: assignment, t[i] = s[j]
  // op2: do nothing,
  int dp(vector<int>& t, vector<int>& s, int i, int j, int op) {
    if(i >= t.size()) return 0;

    int& res = op == 1 ? memo1_[i][j] : memo2_[i][j];

    // has been calculated
    if(res != MAX_VAL) return res;

    int prev;
    if(op == 1)
      prev = s[j];  // op1
    else if (op == 2)
      prev = i == 0 ? INT_MIN : t[i - 1];  // op2

    // find the next s[j] can be used
    j = upper_bound(s.begin() + j, s.end(), prev) - s.begin();

    if(j < s.size()) { // op1
      res = dp(t, s, i + 1, j, 1) + 1;
    }

    if(prev < t[i]) { // op2
      res = min(res, dp(t, s, i + 1, j, 2));
    }

    return res;
  }
};
// @lc code=end

