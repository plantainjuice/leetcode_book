/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution {
 public:
  int numWays(int steps, int arrLen) {
    int size = min(steps / 2 + 1, arrLen);
    vector<int> dp1(size + 2), dp2(size + 2);
    dp1[1] = 1;

    constexpr int MOD = 1e9 + 7;

    while (steps--) {
      for (int i = 1; i <= size; ++i)
        dp2[i] = ((long)dp1[i - 1] + dp1[i] + dp1[i + 1]) % MOD;

      swap(dp1, dp2);
    }

    return dp1[1];
  }
};
// @lc code=end

