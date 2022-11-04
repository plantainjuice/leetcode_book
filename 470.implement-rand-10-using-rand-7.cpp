/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    while (true) {
      int r1 = rand7();
      int r2 = rand7();

      int idx = (r1 - 1) * 7 + r2;
      if (idx <= 40) return 1 + idx % 10;
    }

    return -1;
  }
};
// @lc code=end

