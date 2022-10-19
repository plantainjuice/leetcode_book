/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    long minmax = 0;
    long sum = 0;
    for (long i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      minmax = max((sum + i) / (i + 1), minmax);
    }
    return minmax;
  }
};
// @lc code=end

