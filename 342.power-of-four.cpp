/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfFour(int n) {
    while (n >= 4) {
      if (n % 4 == 0) {
        n = n / 4;
      } else {
        return false;
      }
    }

    return n == 1;
  }
};
// @lc code=end

