/*
 * @lc app=leetcode id=1828 lang=cpp
 *
 * [1828] Queries on Number of Points Inside a Circle
 */

// @lc code=start
class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> ans;

    for (vector<int>& q : queries) {
      int x = q[0];
      int y = q[1];
      int r = q[2];
      int cnt = 0;

      for (vector<int> p : points) {
        int dx2 = (p[0] - x) * (p[0] - x);
        int dy2 = (p[1] - y) * (p[1] - y);

        if (dx2 + dy2 <= r * r) ++cnt;
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// @lc code=end
