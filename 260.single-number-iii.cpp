/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  // https://segmentfault.com/a/1190000004886431
  vector<int> singleNumber(vector<int>& nums) {
    long mix = 0;
    for (int num : nums) {
      mix ^= num;
    }

    // the bit `A` has, but `B` dose not.
    int diff_bit = (mix & -mix);

    int A = 0, B = 0;

    for (int num : nums) {
      if (num & diff_bit) {
        A ^= num;
      } else {
        B ^= num;
      }
    }

    return {A, B};
  }
};
// @lc code=end

