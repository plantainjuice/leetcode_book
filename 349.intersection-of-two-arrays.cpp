/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <algorithm>
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    set<int> s1{nums1.begin(), nums1.end()};

    for (const int num : nums2) {
      if (!s1.count(num)) continue;
      ans.push_back(num);
      s1.erase(num);
    }

    return ans;
  }
};
// @lc code=end

