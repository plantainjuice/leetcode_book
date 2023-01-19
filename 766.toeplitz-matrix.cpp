/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& M) {
    int m = M.size();
    int n = M[0].size();

    for (int i = 0; i < m - 1; ++i)
      for (int j = 0; j < n - 1; ++j)
        if (M[i][j] != M[i + 1][j + 1]) return false;

    return true;
  }
};
// @lc code=end

