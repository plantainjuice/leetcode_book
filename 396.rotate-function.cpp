/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    int F0 = 0;
    for (int i = 0; i < n; ++i) F0 += i * nums[i];

    int mx = F0;
    int last = F0;
    for (int i = 1; i < n; ++i) {
      last = last + sum - n * (nums[n - i]);
      mx = max(mx, last);
    }

    return mx;
  }
};
// @lc code=end
