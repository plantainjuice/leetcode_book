/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    // vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    // hp[m][n-1] = hp[m-1][n] = 1;
    vector<int> hp(n + 1, INT_MAX);
    hp[n - 1] = 1;

    for (int y = m - 1; y >= 0; --y)
      for (int x = n - 1; x >= 0; --x)
        hp[x] = max(1, min(hp[x + 1], hp[x]) - dungeon[y][x]);

    return hp[0];
  }
};
// @lc code=end

