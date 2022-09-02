/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());

    int j = 0;
    int k = (nums.size() + 1) / 2;
    for (int i = nums.size() - 1; i >= 0; --i) {
      nums[i] = sorted[i & 1 ? k++ : j++];
    }
  }
};
// @lc code=end

