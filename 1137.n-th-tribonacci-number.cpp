/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
      if (n <= 2) return n == 0 ? 0 : 1;

      // relative no.
      int T_0 = 0;
      int T_1 = 1;
      int T_2 = 1;

      for(int i = 3; i <= n; ++i) {
        int tmp = T_0 + T_1 + T_2;

        T_0 = T_1;
        T_1 = T_2;
        T_2 = tmp;
      }

      return T_2;
    }
};
// @lc code=end

