/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
 public:
  bool isUgly(int n) {
    int i = 2;
    while (n > 1) {
      while (n % i == 0) n /= i;

      ++i;

      if (i > 5) break;
    }

    return n == 1;
  }
};
// @lc code=end
