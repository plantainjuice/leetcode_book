/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start

// https://www.youtube.com/watch?v=QlMyXlhI3Ic
class Solution {
 public:
  int countDigitOne(int n) {
    int ans = 0;

    for (long i = 1; i <= n; i = i * 10) {
      int cur = (n % (10 * i)) / i;
      int low_part = n % i;
      int high_part = n / (10 * i);

      if (cur == 0) {
        ans += (high_part)*i;
      } else if (cur == 1) {
        ans += (high_part)*i + (low_part + 1);
      } else {
        ans += (high_part + 1) * i;
      }
    }

    return ans;
  }
};
// @lc code=end

