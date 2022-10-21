/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) != m.end()) {
        if (i - m[nums[i]] <= k) return true;
      }
      m[nums[i]] = i;
    }

    return false;
  }
};
// @lc code=end

