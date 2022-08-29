/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();

    vector<int> ans(n, 1);
    int l = 1;
    int r = 1;
    for (int i = 0; i < n; ++i) {
      ans[i] *= l;
      ans[n - i - 1] *= r;
      l *= nums[i];
      r *= nums[n - i - 1];
    }

    return ans;
  }
};
// @lc code=end

