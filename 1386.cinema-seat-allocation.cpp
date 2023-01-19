/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

// @lc code=start
class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int no = 0;

    vector<pair<int, int>> v;
    for (int i = 0; i < reservedSeats.size(); ++i)
      v.push_back({reservedSeats[i][0], reservedSeats[i][1]});

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
      int d = v[i].first;
      int f = 0, g = 0, h = 0, k = 0;

      while (d == v[i].first) {
        int seat = v[i].second;
        if (seat == 2 || seat == 3) f = 1;
        if (seat == 4 || seat == 5) g = 1;
        if (seat == 6 || seat == 7) h = 1;
        if (seat == 8 || seat == 9) k = 1;

        ++i;
        if (i == v.size()) break;
      }

      --i;

      if (f == 1 || g == 1) ++no;
      if (h == 1 || k == 1) ++no;

      if (g == 0 && h == 0 && f == 1 && k == 1) --no;
    }

    return 2 * n - no;
  }
};
// @lc code=end
