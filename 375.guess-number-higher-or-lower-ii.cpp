/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> memo(201, vector<int>(201, -1));

    function<int(int, int)> f;
    f = [&](int l, int h) {
      if (l >= h) return 0;

      if (memo[l][h] != -1) return memo[l][h];

      int res = INT_MAX;

      // for (int i = l; i <= h; ++i) {

      // only need take the high-part into consideration
      for (int i = h; i >= (l + h) / 2; --i) {
        int r = i + max(f(l, i - 1), f(i + 1, h));
        res = min(r, res);
      }

      memo[l][h] = res;
      return res;
    };

    return f(1, n);
  }
};
// @lc code=end

