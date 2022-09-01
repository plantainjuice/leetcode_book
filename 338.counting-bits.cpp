/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);

    for (int i = 0; i <= n; ++i) {
      ans[i] = bitset<32>(i).count();
    }

    return ans;
  }
};
// @lc code=end

