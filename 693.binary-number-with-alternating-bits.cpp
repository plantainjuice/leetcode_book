/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int c = n % 2;

    while (n) {
      if (n % 2 != c) return false;

      n = n >> 1;

      c = c == 1 ? 0 : 1;
    }

    return true;
  }
};
// @lc code=end
