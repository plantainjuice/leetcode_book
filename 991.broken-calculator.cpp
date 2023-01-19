/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
 public:
  int brokenCalc(int startValue, int target) {
    if(startValue >= target) return startValue - target;

    if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);

    return 1 + brokenCalc(startValue, target + 1);
  }
};
// @lc code=end
