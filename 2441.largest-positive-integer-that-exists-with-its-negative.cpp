/*
 * @lc app=leetcode id=2441 lang=cpp
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */

// @lc code=start
class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size() - 1;

    while (i < j) {
      if (-1 * nums[i] == nums[j])
        return nums[j];
      else if (-1 * nums[i] < nums[j])
        --j;
      else
        ++i;
    }

    return -1;
  }
};
// @lc code=end

