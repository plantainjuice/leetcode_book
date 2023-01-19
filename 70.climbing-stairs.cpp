/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) return n;

    int n_2 = 1;
    int n_1 = 2;
    int cur = 0;

    n -= 2;
    while (n--) {
      cur = n_1 + n_2;
      n_2 = n_1;
      n_1 = cur;
    }

    return cur;
  }
};
// @lc code=end
