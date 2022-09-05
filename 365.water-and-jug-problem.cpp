/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1 + j2 < t) return false;
        return t % (gcd(j1, j2)) == 0;
    }
};
// @lc code=end

