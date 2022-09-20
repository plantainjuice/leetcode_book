/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int allsum = 0;
    for (int n : nums) allsum += n;

    // can no be divided into k parts
    if (allsum % k != 0) return false;

    int target = allsum / k;

    vector<bool> mask(nums.size(), false);

    sort(nums.begin(), nums.end(), greater<int>());

    find_ = false;
    dfs(nums, mask, target, 0, k, 0);

    return find_;
  }

 private:
  bool find_;

  void dfs(vector<int>& nums, vector<bool>& mask, int target, int i, int k, int cur) {
    if (k == 1) {
      find_ = true;
      return;
    }

    // end
    if (i == nums.size() || cur > target) return;

    // find one
    if (cur == target) return dfs(nums, mask, target, 0, k - 1, 0);

    // choose i
    if (!mask[i]) {
      mask[i] = true;
      dfs(nums, mask, target, i + 1, k, cur + nums[i]);
      mask[i] = false;
    }

    // not choose i
    dfs(nums, mask, target, i + 1, k, cur);
  }
};
// @lc code=end

