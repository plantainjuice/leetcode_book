/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r) {
      int mid = (r - l) / 2 + l;

      if(nums[mid] == target) return mid;

      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return nums[l] < target ? l + 1 : l;
  }
};
// @lc code=end

