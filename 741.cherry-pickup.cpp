/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=star//https://leetcode.com/problems/cherry-pickup/discuss/1912865/C%2B%2B-oror-Detailed-Explanation-and-clear-Intuitions-oror-Memoization-oror-DP-oror-Good-Questiont
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));

    int res = dfs(0, 0, 0, 0, grid, memo);
    return max(res, 0);
  }

  // imagine that there have 2 man walk simultaneously
  // man1: <c1, r1>, man2: <c2, r2>
  int dfs(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
    int n = grid.size();
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
      return INT_MIN;

    // has calculated
    if(memo[r1][c1][r2] != -1) return memo[r1][c1][r2];

    // at end
    if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];

    int ans = grid[r1][c1];
    if (r1 != r2) {
      ans += grid[r2][c2];
    }

    int a1 = dfs(r1 + 1, c1, r2 + 1, c2, grid, memo);
    int a2 = dfs(r1 + 1, c1, r2, c2 + 1, grid, memo);
    int a3 = dfs(r1, c1 + 1, r2 + 1, c2, grid, memo);
    int a4 = dfs(r1, c1 + 1, r2, c2 + 1, grid, memo);

    ans += max({a1, a2, a3, a4});

    return memo[r1][c1][r2] = ans;
  }
};
// @lc code=end

