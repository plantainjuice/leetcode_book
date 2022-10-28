/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
 public:
 static constexpr int MOD = 1e9 + 7;
  int sumSubarrayMins(vector<int>& A) {
    stack<pair<long, int>> PLE, NLE; // previous less element, next less element
    // L is for the distance to previous less element
    // R is for the distance to next less element
    vector<long> L(A.size()), R(A.size());

    // initialize
    iota(L.begin(), L.end(), 1);
    iota(R.rbegin(), R.rend(), 1);

    for (int i = 0; i < A.size(); i++) {
      // for previous less
      while (!PLE.empty() && PLE.top().first > A[i]) PLE.pop();
      L[i] = PLE.empty() ? i + 1 : i - PLE.top().second;
      PLE.push({A[i], i});

      // for next less
      while (!NLE.empty() && NLE.top().first > A[i]) {
        auto x = NLE.top();
        NLE.pop();
        R[x.second] = i - x.second;
      }
      NLE.push({A[i], i});
    }

    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
      ans = (ans + A[i] * L[i] * R[i]) % MOD;
    }
    return ans;
  }
};
// @lc code=end

