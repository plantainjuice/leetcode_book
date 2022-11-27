/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ans = 0;
    unordered_map<long, int> m[A.size()];

    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j < i; ++j) {
        long diff = (long)A[i] - A[j];

        int cnt = m[j][diff];
        m[i][diff] += cnt + 1;
        ans += cnt;
      }

    return ans;
  }
};
// @lc code=end
