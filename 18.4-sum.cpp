/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int k = 0; k < nums.size(); ++k) {
      // remove duplicate
      if (k > 0 && nums[k - 1] == nums[k]) continue;

      for (int i = k + 1; i < nums.size(); ++i) {
        // prune
        if (nums[k] + nums[i] > target && nums[k] + nums[i] > 0) break;

        // remove duplicate
        if (i > k + 1 && nums[i - 1] == nums[i]) continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
          long sum = (long)nums[k] + nums[i] + nums[left] + nums[right];
          if (sum > target) {
            --right;
          } else if (sum < target) {
            ++left;
          } else {
            ans.push_back({nums[k], nums[i], nums[left], nums[right]});

            while (left < right && nums[left + 1] == nums[left]) ++left;
            while (left < right && nums[right - 1] == nums[right]) --right;

            ++left;
            --right;
          }
        }
      }
    }

    return ans;
  }
};
// @lc code=end

