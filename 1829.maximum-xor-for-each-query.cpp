/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int m = (1 << maximumBit) - 1;

    vector<int> ans;

    int XOR = nums[0];
    ans.push_back(m ^ XOR);

    for (int i = 1; i < nums.size(); ++i) {
      XOR ^= nums[i];

      ans.push_back(m ^ XOR);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
