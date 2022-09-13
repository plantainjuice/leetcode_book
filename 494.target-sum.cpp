/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // prune
    if (abs(target) > sum) return 0;

    // assumpt that: sum(all positive) = x,
    // then: sum(all negative) = - (sum - x)
    // and given: x - (sum - x) = target
    // => 2x = (target + sum)

    // (target + sum) must be even
    if ((target + sum) % 2 != 0) return 0;

    int S = (target + sum) / 2;

    if (S < 0) return 0;

    vector<int> dp(S + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = S; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }

    return dp[S];
  }
};
// @lc code=end

