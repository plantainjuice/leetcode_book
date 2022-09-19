/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
public:
 int largestIsland(vector<vector<int>>& grid) {
    g_ = &grid;
    n_ = grid.size();

    int ans = 0;

    int color = 1;
    for (int i = 0; i < n_; ++i)
      for (int j = 0; j < n_; ++j)
        if ((*g_)[i][j] == 1) {
          int area = getArea(i, j, ++color);
          areas_[color] = area;
          ans = max(ans, area);
        }

    for (int i = 0; i < n_; ++i)
      for (int j = 0; j < n_; ++j)
        if ((*g_)[i][j] == 0) {
          int area = 1;
          for (int c : set<int>{getColor(i + 1, j), getColor(i - 1, j),
                                getColor(i, j + 1), getColor(i, j - 1)})
            area += areas_[c];
          ans = max(ans, area);
        }

    return ans;
 }

private:
 int getColor(int x, int y) {
   if (x < 0 || y < 0 || x >= n_ || y >= n_) return 0;
   return (*g_)[x][y];
 }

 int getArea(int x, int y, int color) {
   if (x < 0 || y < 0 || x >= n_ || y >= n_ || (*g_)[x][y] != 1) return 0;

   (*g_)[x][y] = color;

   return 1 + getArea(x + 1, y, color) + getArea(x - 1, y, color) +
          getArea(x, y + 1, color) + getArea(x, y - 1, color);
 }

private:
 int n_;
 vector<vector<int>>* g_;
 map<int, int> areas_; // color -> area
};
// @lc code=end

