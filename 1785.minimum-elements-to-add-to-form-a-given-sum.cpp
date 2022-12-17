/*
 * @lc app=leetcode id=1785 lang=cpp
 *
 * [1785] Minimum Elements to Add to Form a Given Sum
 */

// @lc code=start
class Solution {
 public:
  int minElements(vector<int>& nums, int limit, int goal) {
    long sum = accumulate(nums.begin(), nums.end(), 0L);

    long diff = abs(goal - sum);

    int ans = (diff / limit);

    if (diff % limit == 0) return ans;

    return ans + 1;
  }
};
// @lc code=end
