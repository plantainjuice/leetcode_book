/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
 public:
  int numTilings(int n) {
    constexpr int MOD = 1e9 + 7;

    vector<long> memo(n + 1, -1);
    function<int(int)> dp = [&](int i) -> int {
      if (i == 0) return 0;
      if (i == 1) return 1;
      if (i == 2) return 2;
      if (i == 3) return 5;

      if (memo[i] > 0) return memo[i];

      long r1 = dp(i - 1) * 2;
      long r2 = dp(i - 3);
      int sum = (r1 + r2) % MOD;

      return memo[i] = sum;
    };

    int ans = dp(n);

    return ans;
  }
};
// @lc code=end
