/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i += 2) {
      int cnt = nums[i];
      int ele = nums[i + 1];

      while (cnt--) ans.push_back(ele);
    }

    return ans;
  }
};
// @lc code=end

