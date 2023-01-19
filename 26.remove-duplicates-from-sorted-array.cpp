/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int cur = 1;
    int i = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[i - 1]) nums[cur++] = nums[i];
    }

    return cur;
  }
};
// @lc code=end
