/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      vector<vector<int>> ans = mat;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (ans[i][j] == 1) ans[i][j] = INT_MAX;

      vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

      // TODO use queue for optimization
      int epoch = 1;
      while (true) {
        int change = 0;

        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if (ans[i][j] == epoch - 1) {
              for(auto& d : dr) {
                int _i = i + d.first;
                int _j = j + d.second;

                if(0 <= _i && _i < m && 0 <= _j && _j < n) {
                  if(ans[_i][_j] == INT_MAX) {
                    ++change;
                    ans[_i][_j] = min(ans[_i][_j], ans[i][j] + 1);
                  }
                }
              }
            }
          }
        }

        if (change == 0) break;

        ++epoch;
      }

      return ans;
    }
};
// @lc code=end

