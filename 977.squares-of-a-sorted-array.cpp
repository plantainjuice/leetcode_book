/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans(nums.size());
    int l = 0, r = nums.size() - 1;

    int cur = nums.size() - 1;
    while (l <= r) {
      if (abs(nums[l]) >= abs(nums[r])) {
        ans[cur] = nums[l] * nums[l];
        ++l;
      } else {
        ans[cur] = nums[r] * nums[r];
        --r;
      }
      --cur;
    }

    return ans;
  }
};
// @lc code=end

