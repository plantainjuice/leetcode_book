/*
 * @lc app=leetcode id=2411 lang=cpp
 *
 * [2411] Smallest Subarrays With Maximum Bitwise OR
 */

// @lc code=start
class Solution {
//https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/discuss/2589637/Closest-Position-of-Each-Bit
public:
vector<int> smallestSubarrays(vector<int>& nums) {
  vector<int> res(nums.size()), closest(30);
  for (int i = nums.size() - 1; i >= 0; --i) {
    for (int b = 0; b < 30; ++b)
      if (nums[i] & (1 << b)) closest[b] = i;
    res[i] = max(1, *max_element(begin(closest), end(closest)) - i + 1);
  }
  return res;
}
};
// @lc code=end

