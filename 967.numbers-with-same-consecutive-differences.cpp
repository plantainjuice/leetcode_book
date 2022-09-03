/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ans;

    for (int i = 1; i < 10; ++i) {
      dfs(n - 1, k, i, i, ans);
    }

    return ans;
  }

 private:
  void dfs(int n, int k, int cur, int s, vector<int>& ans) {
    if (n == 0) {
      ans.push_back(s);
      return;
    }

    int add = cur + k;
    int minus = cur - k;

    if (add < 10) {
      dfs(n - 1, k, add, s * 10 + add, ans);
    }

    if (add == minus) return;

    if (minus >= 0) {
      dfs(n - 1, k, minus, s * 10 + minus, ans);
    }
  }
};
// @lc code=end

