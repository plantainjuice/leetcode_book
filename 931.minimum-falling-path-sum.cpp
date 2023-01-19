/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    if(n == 1) return matrix[0][0];

    vector<int> last_row = matrix[0];

    for (int row = 1; row < n; ++row) {
      vector<int> tmp = matrix[row];

      for (int i = 0; i < n; ++i) {
        if (i == 0) {
          tmp[i] += min(last_row[i], last_row[i + 1]);
          continue;
        }

        if (i == n - 1) {
          tmp[i] += min(last_row[i - 1], last_row[i]);
          continue;
        }

        tmp[i] += min({last_row[i - 1], last_row[i], last_row[i + 1]});
      }

      last_row = move(tmp);
    }

    int min_sum = *min_element(last_row.begin(), last_row.end());

    return min_sum;
  }
};
// @lc code=end
