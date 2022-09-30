/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for(int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            rows[i] = rows[i] || (matrix[i][j] == 0);
            cols[j] = cols[j] || (matrix[i][j] == 0);
          }
        }

        for(int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if (rows[i] || cols[j]) matrix[i][j] = 0;
          }
        }
    }
};
// @lc code=end

