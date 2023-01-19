/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
class Solution {
 public:
  int partitionDisjoint(vector<int>& nums) {
    int n = nums.size(), left[n], right[n];

    left[0] = nums[0];
    for (int i = 1; i < n; i++) left[i] = max(left[i - 1], nums[i]);

    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) right[i] = min(right[i + 1], nums[i]);

    for (int i = 0; i < n - 1; i++)
      if (left[i] <= right[i + 1]) return i + 1;

    return -1;
  }
};
// @lc code=end

