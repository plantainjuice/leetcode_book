/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> m;
    for (int n1 : nums1)
      for (int n2 : nums2) m[n1 + n2]++;

    int count = 0;
    for (int n3 : nums3)
      for (int n4 : nums4) {
        if (m.find(0 - n3 - n4) != m.end()) {
          count += m[0 - n3 - n4];
        }
      }

    return count;
  }
};
// @lc code=end

