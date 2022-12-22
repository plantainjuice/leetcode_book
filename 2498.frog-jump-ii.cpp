/*
 * @lc app=leetcode id=2498 lang=cpp
 *
 * [2498] Frog Jump II
 */

// @lc code=start
class Solution {
 public:
  int maxJump(vector<int>& S) {
    int n = S.size();

    if (n == 2) return S[1];

    int odd = S[1];
    int even = S[2];
    int ans = max(odd, even);

    for (int i = 1; i + 2 < n; ++i) {
      if (i % 2 == 1) odd = max(odd, abs(S[i + 2] - S[i]));
      if (i % 2 == 0) even = max(even, abs(S[i + 2] - S[i]));
    }

    if (n % 2 == 1)
      odd = max(odd, abs(S[n - 1] - S[n - 2]));
    else
      even = max(even, abs(S[n - 1] - S[n - 2]));

    ans = max(ans, max(odd, even));

    return ans;
  }
};
// @lc code=end
