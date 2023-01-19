/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    // Returns the number of subarrays with k or less distinct numbers.
    auto subarrys = [&nums](int k) {
      vector<int> count(nums.size() + 1);
      int ans = 0;
      int i = 0;
      for (int j = 0; j < nums.size(); ++j) {
        if (count[nums[j]]++ == 0) --k;
        while (k < 0)
          if (--count[nums[i++]] == 0) ++k;
        ans += j - i + 1;
      }
      return ans;
    };

    return subarrys(k) - subarrys(k - 1);
  }
};
// @lc code=end

