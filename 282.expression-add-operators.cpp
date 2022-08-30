/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;

    dfs(0, num, target, 0, 0, "", &ans);

    return ans;
  }

 private:
  void dfs(int pos, const string& num, int target, long prev, long curr,
           const string& expr, vector<string>* ans) {
    if (pos == num.size()) {
      if (curr == target) ans->push_back(expr);
      return;
    }

    for (int l = 1; l <= num.size() - pos; ++l) {
      string t = num.substr(pos, l);
      if (t[0] == '0' && t.size() > 1) break;
      long n = stol(t);
    //   if (n > INT_MAX) break;

      // special case
      if (pos == 0) {
        dfs(pos + l, num, target, n, n, t, ans);
        continue;
      }

      dfs(pos + l, num, target, n, curr + n, expr + "+" + t, ans);
      dfs(pos + l, num, target, -n, curr - n, expr + "-" + t, ans);
      dfs(pos + l, num, target, prev * n, curr - prev + prev * n, expr + "*" + t, ans);
    }
  }
};
// @lc code=end

