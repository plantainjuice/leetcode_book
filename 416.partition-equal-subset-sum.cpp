/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // prune
    if (sum % 2 == 1) return false;

    int target = sum / 2;
    // vector<int> dp(target + 1);
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = dp[j] || dp[j - nums[i]];
      }
    }

    // return dp[target] == target;
    return dp[target];
  }
};
// @lc code=end

