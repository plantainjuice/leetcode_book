/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int lsum = 0;
    int rsum = accumulate(nums.begin(), nums.end(), 0);

    int i = 0;
    while(i < nums.size()) {
      rsum -= nums[i];

      if (lsum == rsum) return i;

      lsum += nums[i];
      ++i;
    }


    return -1;
  }
};
// @lc code=end

