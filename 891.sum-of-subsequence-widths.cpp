/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */

// @lc code=start
class Solution {
 public:
  int sumSubseqWidths(vector<int>& A) {
    constexpr int MOD = 1e9 + 7;

    int n = A.size(), i, j = n - 1;

    sort(A.begin(), A.end());

    long p = 1;
    long ans = 0;

    for (i = 0; i < n; i++) {
      ans += p * (A[i] - A[j]);
      ans = ans % MOD;

      p = (p * 2) % MOD;

      j--;
    }
    return ans;
  }
};
// @lc code=end
