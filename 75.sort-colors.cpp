/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();

    int l = 0, h = n - 1;
    int cur = 0;

    while (cur <= h) {
      if (nums[cur] == 0) {
        swap(nums[l++], nums[cur++]);
      } else if (nums[cur] == 1) {
        cur++;
      } else {
        swap(nums[h--], nums[cur]);
      }
    }
  }
};
// @lc code=end

