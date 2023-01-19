/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
class Solution {
 public:
  int nthMagicalNumber(int N, int A, int B) {
    constexpr int MOD = 1e9 + 7;

    long lcm = A * B / __gcd(A, B);
    long l = 2;
    long r = 1e14;

    while (l < r) {
      long m = (l + r) / 2;

      if (m / A + m / B - m / lcm < N)
        l = m + 1;
      else
        r = m;
    }

    return l % MOD;
  }
};
// @lc code=end
