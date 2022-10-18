/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
      if (r > 0 && nums[r - 1] == nums[r]) {
        --r;
        continue;
      }
      if (l < nums.size() - 1 && nums[l + 1] == nums[l]) {
        ++l;
        continue;
      };

      int mid = l + (r - l) / 2;
      if (nums[mid] < nums[r]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return nums[l];
  }
};
// @lc code=end

