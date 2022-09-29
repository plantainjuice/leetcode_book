/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution {
  // https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/2031309/C%2B%2B-Easy-to-Understand-Detailed-Explanation-Beginner-Friendly-Binary-Search
  // 非严格单调递减函数，给定y，求x最小值
 public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int low = 1;
    int high = 1e9;

    while (low < high) {
      int mid = low + (high - low) / 2;

      int splitOperations = 0;

      for (int bag : nums) splitOperations += (bag - 1) / mid;

      if (splitOperations > maxOperations) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
// @lc code=end

