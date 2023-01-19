/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */

// @lc code=start
class Solution {
 public:
  int reachNumber(int target) {
    target = abs(target);

    int steps = 0;
    int sum = 0;
    while (sum < target) {
      ++steps;
      sum += steps;
    }

    if (sum == target) return steps;

    int diff = sum - target;

    if (diff % 2 == 0) return steps;

    if (steps % 2 == 0)
      return steps + 1;
    else
      return steps + 2;

    return -1;
  }
};
// @lc code=end

