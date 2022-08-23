/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
 // solution 1
 void rotate(vector<int>& nums, int k) {
   int n = nums.size();
   if (n == 0) return;

   k = k % n;
   if (k == 0) return;

   reverse(begin(nums), end(nums));
   reverse(begin(nums), begin(nums) + k);
   reverse(begin(nums) + k, end(nums));
 }
};
// @lc code=end

