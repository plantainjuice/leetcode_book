/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end

