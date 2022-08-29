/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int m = matrix.size();
    int n = matrix[0].size();

    int r = 0;      // row
    int c = n - 1;  // col
    while (r < m && c >= 0) {
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] > target)
        --c;
      else
        ++r;
    }

    return false;
  }
};
// @lc code=end

