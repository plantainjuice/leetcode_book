/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int ans = 1;
    int last = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1])
        ++last;
      else
        last = 1;

      ans = max(ans, last);
    }

    return ans;
  }
};
// @lc code=end

