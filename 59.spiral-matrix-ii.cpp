/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    int startX = 0;
    int startY = 0;

    int count = 1;
    int offset = 1;

    int loop = n / 2;
    while(loop--) {
      int i = startX;
      int j = startY;

      for (; j < n - offset; ++j) res[i][j] = count++;

      for (; i < n - offset; ++i) res[i][j] = count++;

      for (; j > startY; --j) res[i][j] = count++;

      for (; i > startX; --i) res[i][j] = count++;

      ++startX;
      ++startY;

      ++offset;
    }

    if (n % 2 == 1) {
      int mid = n / 2;
      res[mid][mid] = count;
    }

    return res;
  }
};
// @lc code=end

