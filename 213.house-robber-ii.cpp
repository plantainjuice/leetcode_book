/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);

    int n = nums.size();

    int l = _rob(nums, 0, n - 2);
    int r = _rob(nums, 1, n - 1);

    return max(l, r);
  }

private:
  int _rob(vector<int>& nums, int start, int end) {
    int n = nums.size();

    vector<int> dp(n);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[end];
  }
};
// @lc code=end

