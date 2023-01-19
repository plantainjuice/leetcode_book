/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
 */

// @lc code=start
class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    int part1[2] = {};
    int part2[2] = {};

    for (int i = 0; i < n; ++i) part1[i % 2] += nums[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      part1[i % 2] -= nums[i];

      if (part1[1] + part2[0] == part1[0] + part2[1]) ++cnt;

      part2[i % 2] += nums[i];
    }

    return cnt;
  }
};
// @lc code=end
