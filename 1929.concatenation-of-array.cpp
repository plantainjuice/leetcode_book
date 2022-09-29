/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    nums.insert(nums.end(), nums.begin(), nums.end());
    return nums;
  }
};
// @lc code=end

