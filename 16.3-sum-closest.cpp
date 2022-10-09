/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int closest = nums[0] + nums[1] + nums[2];

    for (int k = 0; k < nums.size(); ++k) {
      // duplicate, pruning
      if (k > 0 && nums[k] == nums[k - 1]) continue;

      int i = k + 1;
      int j = nums.size() - 1;

      // two pointer
      while (i < j) {
        int three_sum = nums[k] + nums[i] + nums[j];

        if (abs(closest - target) > abs(three_sum - target))
          closest = three_sum;

        if (three_sum > target) {
          j--;
        } else if (three_sum < target) {
          i++;
        } else {
          return closest; // find target
        }
      }
    }

    return closest;
  }
};
// @lc code=end

