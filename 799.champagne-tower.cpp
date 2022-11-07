/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> currRow(1, poured);

    for (int i = 0; i <= query_row; i++) {
      vector<double> nextRow(i + 2, 0);
      for (int j = 0; j <= i; j++) {
        if (currRow[j] >= 1) {
          nextRow[j] += (currRow[j] - 1) / 2.0;
          nextRow[j + 1] += (currRow[j] - 1) / 2.0;
        }
      }
      if (i != query_row) currRow = nextRow;
    }
    return min(1.0, currRow[query_glass]);
  }
};
// @lc code=end

