/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    set<int> S;

    for (int i = 1; i < strs.size(); ++i) {
      for (int j = 0; j < strs[0].size(); ++j) {
        if (S.count(j) > 0 || strs[i][j] == strs[i - 1][j]) continue;
        if (strs[i - 1][j] > strs[i][j]) {
          S.insert(j);
          i = 0;
        }
        break;
      }
    }

    return S.size();
  }
};
// @lc code=end

