/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
class Solution {
 public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    memo_ = vector<vector<int>>(n, vector<int>(2, -1)); // n * 2

    int r1 = dp(nums1, nums2, 0, -1, -1, 1);
    int r2 = dp(nums1, nums2, 0, -1, -1, 0);

    return min(r1, r2);
  }

private:
  vector<vector<int>> memo_;

  // 0 -> op1: swap
  // 1 -> op2: not swap
  int dp(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2, int op) {
    if(i == nums1.size()) return 0;

    if(memo_[i][op] != -1) return memo_[i][op];

    int res = 1e5;

    // op1
    if (nums1[i] > prev1 && nums2[i] > prev2)
      res = min(res, dp(nums1, nums2, i + 1, nums1[i], nums2[i], 1) + 1);

    // op2
    if (nums1[i] > prev2 && nums2[i] > prev1)
      res = min(res, dp(nums1, nums2, i + 1, nums2[i], nums1[i], 0));

    return memo_[i][op] = res;
  }
};
// @lc code=end

