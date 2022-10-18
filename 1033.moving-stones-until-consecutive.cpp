/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */

// @lc code=start
class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> s = {a, b, c};
    sort(begin(s), end(s));
    if (s[2] - s[0] == 2) return {0, 0};
    return {min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2};
  }
};
// @lc code=end

