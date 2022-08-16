/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
#include <map>
#include <functional>

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) return points.size();

        // gcd
        function<int(int, int)> gcd;
        gcd = [&gcd](int m, int n) -> int { return n == 0 ? m : gcd(n, m % n); };

        // use pair to represent the slope of point1 & point2
        auto get_slope = [&gcd](int x1, int y1, int x2,
                            int y2) -> std::pair<int, int> {
          const int delta_x = x1 - x2;
          const int delta_y = y1 - y2;

          if (delta_x == 0) return {0, 1};

          if (delta_y == 0) return {1, 0};

          const int d = gcd(delta_x, delta_y);
          return {delta_x / d, delta_y / d};
        };

        // max points on same line with point i
        auto max_points_on_one_line_with_point_i = [&](int i) {
          map<pair<int, int>, int> slope_counts;
          int same_points = 1;
          int count = 0;

          for (int j = i + 1; j < points.size(); ++j) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];

            if (x1 == x2 && y1 == y2) {
                same_points++;
                continue;
            }

            count = max(count, ++slope_counts[get_slope(x1, y1, x2, y2)]);
          }

          return count + same_points;
        };

        // iterate
        int max_count = 1;
        for (int i = 0; i < points.size(); ++i) {
            int count = max_points_on_one_line_with_point_i(i);
            max_count = max(max_count, count);
        }

        return max_count;
    }
};
// @lc code=end

