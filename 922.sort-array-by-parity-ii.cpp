/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int even_index = 0;
    int odd_index = 1;

    while (odd_index < nums.size()) {
      if (nums[odd_index] % 2 == 0) {
        while (nums[even_index] % 2 == 0) even_index += 2;
        swap(nums[odd_index], nums[even_index]);
      }
      odd_index += 2;
    }

    return nums;
  }
};
// @lc code=end

