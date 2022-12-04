/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();

    long S = 0;
    for (int num : nums) S += num;

    long sum = 0;
    long min_avg = LONG_MAX;
    int index = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];

      long part1 = sum / (i + 1);
      long part2 = i < (n - 1) ? (S - sum) / (n - i - 1) : 0;

      long diff = abs(part1 - part2);

      if (diff < min_avg) {
        min_avg = diff;
        index = i;
      }
    }

    return index;
  }
};
// @lc code=end
