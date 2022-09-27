/*
 * @lc app=leetcode id=1536 lang=cpp
 *
 * [1536] Minimum Swaps to Arrange a Binary Grid
 */

// @lc code=start
class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> tail_0(n, 0);

    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j) count++;
      tail_0[i] = count;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
      int k = i;
      int req = n - 1 - i; // zeros request

      while(k < n && tail_0[k] < req) k++;

      // can not find enough zero
      if(k == n) return -1;

      // swap steps
      ans += k - i;

      // simulate the swap
      while(k > i) {
        tail_0[k] = tail_0[k - 1];
        --k;
      }

    }

    return ans;
  }
};
// @lc code=end

