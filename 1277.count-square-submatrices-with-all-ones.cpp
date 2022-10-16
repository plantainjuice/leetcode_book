/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = matrix[i][j];
        if (dp[i][j] && i && j) {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
        res += dp[i][j];
      }
    }

    return res;
  }

  //   int countSquares(vector<vector<int>>& matrix) {
  //     int m = matrix.size();
  //     int n = matrix[0].size();

  //     vector<vector<int>> row(m, vector<int>(n, 0));  // row len
  //     vector<vector<int>> col(m, vector<int>(n, 0));  // col len

  //     for (int i = 0; i < m; ++i) {
  //       for (int j = 0; j < n; ++j) {
  //         if(matrix[i][j] == 0) continue;

  //         col[i][j] = i == 0 ? matrix[i][j] : matrix[i][j] + col[i - 1][j];
  //         row[i][j] = j == 0 ? matrix[i][j] : matrix[i][j] + row[i][j - 1];
  //       }
  //     }

  //     int K = min(m, n);
  //     int res = 0;

  //     vector<vector<bool>> dp(m, vector<bool>(n, true));

  //     for (int k = 1; k <= K; ++k) {
  //       vector<vector<bool>> dp2(m, vector<bool>(n, false));

  //       for (int i = 0; i < m - k + 1; ++i) {
  //         for (int j = 0; j < n - k + 1; ++j) {
  //           // check if square of k
  //           int rbx = i + k - 1;
  //           int rby = j +k -1;
  //           if (dp[i][j] && col[rbx][rby] >= k && row[rbx][rby] >= k) {
  //             dp2[i][j] = true;
  //             ++res;
  //           }
  //         }
  //       }

  //       dp = move(dp2);
  //     }

  //     return res;
  //   }
};
// @lc code=end

