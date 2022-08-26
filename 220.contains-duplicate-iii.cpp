/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
#include <set>

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    std::multiset<long> s;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > k) s.erase(nums[i - k - 1]);

      auto it = s.insert(nums[i]);
      if (it != begin(s) && *it - *prev(it) <= t) return true;
      if (next(it) != end(s) && *next(it) - *it <= t) return true;
    }

    return false;
  }
};
// @lc code=end

