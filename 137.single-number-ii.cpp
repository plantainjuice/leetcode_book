/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
// https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int x1 = 0, x2 = 0, mask = 0;

    for (int num : nums) {
        x2 ^= (x1 & num);
        x1 ^= num;
        mask = ~(x1 & x2);
        x1 = mask & x1;
        x2 = mask & x2;
    }

    return x1;
  }
};
// @lc code=end

