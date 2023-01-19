/*
 * @lc app=leetcode id=2012 lang=cpp
 *
 * [2012] Sum of Beauty in the Array
 */

// @lc code=start
class Solution {
 public:
  int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxs(n, 0);
    vector<int> mins(n, 100001);

    maxs[0] = nums[0];
    for (int i = 1; i < n - 1; ++i) maxs[i] = max(maxs[i - 1], nums[i - 1]);

    mins[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 1; --i) mins[i] = min(mins[i + 1], nums[i + 1]);

    int sumOfBeauty = 0;
    for (int i = 1; i < n - 1; ++i) {
      if (maxs[i] < nums[i] && nums[i] < mins[i])
        sumOfBeauty += 2;
      else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        sumOfBeauty += 1;
    }

    return sumOfBeauty;
  }
};
// @lc code=end
