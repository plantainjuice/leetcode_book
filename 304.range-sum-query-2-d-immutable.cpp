/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& M) : R_(M.size(), vector<int>(M[0].size(), 0)) {
    int m = M.size();
    int n = M[0].size();

    R_[0][0] = M[0][0];

    for (int i = 1; i < m; ++i) R_[i][0] = M[i][0] + R_[i - 1][0];
    for (int j = 1; j < n; ++j) R_[0][j] = M[0][j] + R_[0][j - 1];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        R_[i][j] = M[i][j];
        R_[i][j] += R_[i][j - 1] + R_[i - 1][j] - R_[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = R_[row2][col2];

    if (col1 != 0) sum -= R_[row2][col1 - 1];

    if (row1 != 0) sum -= R_[row1 - 1][col2];

    if (row1 != 0 && col1 != 0) sum += R_[row1 - 1][col1 - 1];

    return sum;
  }

 private:
  vector<vector<int>> R_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

