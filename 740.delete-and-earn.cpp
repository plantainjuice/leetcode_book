/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> vals(10001, 0);

    for (int n : nums) vals[n] += n;

    int last_take = vals[0];
    int last_skip = 0;
    for (int i = 1; i < 10001; ++i) {
      int take = vals[i] + last_skip;
      int skip = max(last_take, last_skip);

      last_take = take;
      last_skip = skip;
    }

    return max(last_take, last_skip);
  }
};
// @lc code=end
