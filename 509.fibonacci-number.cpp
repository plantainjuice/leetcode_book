/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;

        int pre = 0;
        int ans = 1;

        while(--n) {
            int t = pre;
            pre = ans;
            ans = ans + t;
        }

        return ans;
    }
};
// @lc code=end

