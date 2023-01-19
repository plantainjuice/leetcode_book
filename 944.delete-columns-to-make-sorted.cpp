/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int m = strs.size();
    int n = strs[0].size();

    int del = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < m; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          ++del;
          break;
        }
      }
    }

    return del;
  }
};
// @lc code=end

