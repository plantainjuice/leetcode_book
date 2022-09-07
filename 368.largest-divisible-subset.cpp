/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> dp(n);

    for (int i = 0; i < n; ++i) dp[i].push_back(nums[i]);

    int m = 0, m_index = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0) {
          if (dp[j].size() + 1 > dp[i].size()) {
            dp[i] = dp[j];
            dp[i].push_back(nums[i]);
          }
        }
      }

      if (dp[i].size() > m) {
        m_index = i;
        m = dp[i].size();
      }
    }

    return dp[m_index];
  }
};
// @lc code=end

