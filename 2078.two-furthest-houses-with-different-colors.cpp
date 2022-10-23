/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
 public:
  int maxDistance(vector<int>& C) {
    int n = C.size();
    int i = 0, j = n - 1;
    while (C[0] == C[j]) --j;
    while (C[n - 1] == C[i]) ++i;

    return max(j, n - 1 - i);
  }
};
// @lc code=end

