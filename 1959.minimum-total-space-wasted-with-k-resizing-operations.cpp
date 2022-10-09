/*
 * @lc app=leetcode id=1959 lang=cpp
 *
 * [1959] Minimum Total Space Wasted With K Resizing Operations
 */

// @lc code=start
class Solution {
 public:
  Solution() : memo_(200, vector<int>(200, -1)){};

  int minSpaceWastedKResizing(vector<int>& nums, int k) {
    return dp(nums, 0, k);
  }

 private:
  int INF = 200 * 1e6;
  vector<vector<int>> memo_;

  int dp(vector<int>& nums, int i, int k) {
    int n = nums.size();

    if (i == n) return 0;
    if (k == -1) return INF;
    if (memo_[i][k] != -1) return memo_[i][k];

    int ans = INF, maxNum = nums[i], totalSum = 0;
    for (int j = i; j < n; ++j) {
      maxNum = max(maxNum, nums[j]);
      totalSum += nums[j];
      int wasted = maxNum * (j - i + 1) - totalSum;
      ans = min(ans, dp(nums, j + 1, k - 1) + wasted);
    }
    return memo_[i][k] = ans;
  }
};
// @lc code=end

