/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
 public:
  int r, c;
  int countLessThanEqualTo(vector<vector<int>> &grid, int barrier) {
    int res = 0;
    for (int i = 0; i < r; ++i) {
      vector<int> &nums = grid[i];
      res += upper_bound(begin(nums), end(nums), barrier) - begin(nums);
    }
    return res;
  }

  int kthSmallest(vector<vector<int>> &grid, int k) {
    r = grid.size(), c = grid[0].size();
    int lo = -1e9, hi = 1e9, ele = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = countLessThanEqualTo(grid, mid);
      if (cnt >= k)
        ele = mid, hi = mid - 1;
      else
        lo = mid + 1;
    }

    return ele;
 }
};
// @lc code=end

