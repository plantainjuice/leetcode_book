/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // auto power_of_5 = [] (int n) {
        //     int ret = 0;
        //     while (n >= 5 && n % 5 == 0) {
        //         n = n / 5;
        //         ret++;
        //     }

        //     return ret;
        // };

        // int res = 0;
        // for (int i = 5; i <= n; i += 5) {
        //   res += power_of_5(i);
        // }

        // return res;
        return (n / 5) == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
// @lc code=end

