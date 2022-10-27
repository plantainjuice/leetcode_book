/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int neg_cnt = 0;

    for (int i : nums) {
      if (i == 0) return 0;
      if (i < 0) ++neg_cnt;
    }

    return neg_cnt % 2 == 0 ? 1 : -1;
  }
};
// @lc code=end

