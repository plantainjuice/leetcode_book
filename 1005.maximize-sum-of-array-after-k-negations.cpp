/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
      auto cmp = [](int a, int b) { return abs(a) > abs(b); };
      sort(nums.begin(), nums.end(), cmp);

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0 && k > 0) {
          nums[i] *= -1;
          k--;
        }
      }

      if (k % 2 == 1) nums[nums.size() - 1] *= -1;

      int sum = 0;
      for (int n : nums) sum += n;  // 第四步
      return sum;
    }
};
// @lc code=end

