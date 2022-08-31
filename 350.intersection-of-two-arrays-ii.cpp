/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> s1;
    for (const int num : nums1) {
      ++s1[num];
    }

    for (const int num : nums2) {
      auto it = s1.find(num);
      if (it == s1.end() || it->second == 0) continue;

      ans.push_back(num);
      --s1[num];
    }

    return ans;
  }
};
// @lc code=end

