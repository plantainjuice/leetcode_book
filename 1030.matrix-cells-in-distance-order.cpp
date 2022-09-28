/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int n = rows + cols - 2;

        auto is_valid = [&] (int x, int y) {
          return x >= 0 && y >= 0 && x < rows && y < cols;
        };

        vector<vector<int>> ans;
        for (int l = 0; l <= n; ++l) {
          int i = 0;
          for(int j = l - i; j >= 0; --j, ++i) {
            int x = rCenter + i;
            int y = cCenter + j;

            if(is_valid(x, y)) ans.push_back({x, y});

            if (i != 0) {
              x = rCenter - i;
              y = cCenter + j;
              if (is_valid(x, y)) ans.push_back({x, y});
            }

            if (j != 0) {
              x = rCenter + i;
              y = cCenter - j;
              if (is_valid(x, y)) ans.push_back({x, y});
            }

            if (i != 0 && j != 0) {
              x = rCenter - i;
              y = cCenter - j;
              if (is_valid(x, y)) ans.push_back({x, y});
            }
          }
        }

      return ans;
    }
};
// @lc code=end

