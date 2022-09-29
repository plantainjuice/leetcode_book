/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
class Solution {
 public:
  int clumsy(int n) {
    int i = 1;
    int sum = n;
    while (i < n) {
      int num = n - i;
      int index = i % 4;

      if (index == 0) {
        if (i == n - 1) {
          sum -= num;
          i += 1;
        } else if (i == n - 2) {
          sum -= (num * (num - 1));
          i += 2;
        } else {
          sum -= (num * (num - 1) / (num - 2));
          i += 3;
        }

      } else if (index == 1) {
        sum *= num;
        i += 1;
      } else if (index == 2) {
        sum /= num;
        i += 1;
      } else if (index == 3) {
        sum += num;
        i += 1;
      }
    }

    return sum;
  }
};
// @lc code=end

