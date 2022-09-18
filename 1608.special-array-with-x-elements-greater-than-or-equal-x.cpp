/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
 public:
  int specialArray(vector<int>& nums) {
    int n = nums.size();
    int k = n;

    sort(nums.begin(), nums.end());

    if (nums[0] >= k) {
      return k;
    }

    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1]) {
        continue;
      }

      k = n - i;
      if (nums[i] >= k && nums[i - 1] < k) {
        return k;
      }
    }

    return -1;
  }
};
// @lc code=end

