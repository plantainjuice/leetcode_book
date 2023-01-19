/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int max1 = nums[0];
    int max2 = nums[1];
    if (max2 > max1) swap(max1, max2);

    for (int i = 2; i < nums.size(); ++i) {
      int n = nums[i];

      if (n > max1) {
        max2 = max1;
        max1 = n;
        continue;
      }

      if (n > max2) max2 = n;
    }

    return (max1 - 1) * (max2 - 1);
  }
};
// @lc code=end
