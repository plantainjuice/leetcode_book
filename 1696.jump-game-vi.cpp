/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, INT_MIN);
    dp[0] = nums[0];

    deque<int> q;  // monolithic increasing queue
    q.push_back(0);

    for (int i = 1; i < n; ++i) {
      if (q.front() < i - k) q.pop_front();

      int max_i = q.front();
      dp[i] = dp[max_i] + nums[i];

      while (!q.empty() && dp[i] >= dp[q.back()]) {
        q.pop_back();
      }

      q.push_back(i);
    }

    return dp[n - 1];
  }
};
// @lc code=end

