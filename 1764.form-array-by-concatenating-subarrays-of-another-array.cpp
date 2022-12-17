/*
 * @lc app=leetcode id=1764 lang=cpp
 *
 * [1764] Form Array by Concatenating Subarrays of Another Array
 */

// @lc code=start
class Solution {
 public:
  bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    int n = nums.size();

    auto is_match = [&](int begin, vector<int>& g) -> bool {
      int sz = g.size();
      int end = begin + sz - 1;

      if (end >= n) return false;

      for (int i = begin; i <= end; ++i)
        if (nums[i] != g[i - begin]) return false;

      return true;
    };

    int i = 0, j = 0;
    while (i < n && j < groups.size()) {
      vector<int>& group = groups[j];
      if (!is_match(i, group)) {
        ++i;
        continue;
      }

      ++j;
      i += group.size();
    }

    return j == groups.size();
  }
};
// @lc code=end
