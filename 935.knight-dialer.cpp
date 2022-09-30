/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> dial = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
  const int MOD = 1e9 + 7;

  int knightDialer(int n) {
    vector<int> dp1(10, 1), dp2(10);

    while (--n) {
      for (int i = 0; i < 10; ++i)
        dp2[i] =
            accumulate(dial[i].begin(), dial[i].end(), 0,
                       [&](int s, int i) { return (s + dp1[i]) % MOD; });

      swap(dp1, dp2);
    }

    return accumulate(dp1.begin(), dp1.end(), 0,
                      [&](int s, int n) { return (s + n) % MOD; });
  }
};
// @lc code=end

