/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return false;

    int min_1st = min(nums[0], nums[1]);
    int min_2nd = nums[1] > nums[0] ? nums[1] : INT_MAX;

    for (int i = 2; i < n; ++i) {
      if (nums[i] > min_2nd) return true;

      if (nums[i] > min_1st) min_2nd = nums[i];

      if (nums[i] < min_1st) min_1st = nums[i];
    }

    return false;
  }
};
// @lc code=end

