/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
 public:
  int lastRemaining(int n) {
    int head = 1, step = 1;
    bool direction = true;  // true =>, false <=
    while (n > 1) {
      if (direction)
        head += step;
      else
        head += n % 2 == 0 ? 0 : step;
      step *= 2;
      n /= 2;
      direction = !direction;
    }
    return head;
  }
};
// @lc code=end

