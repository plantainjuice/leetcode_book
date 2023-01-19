/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long)m * k > bloomDay.size()) return -1;

    auto func = [&](int day) -> int {
      int cnt = 0;
      int tmp = 0;
      for (int i = 0; i < bloomDay.size(); ++i) {
        if (bloomDay[i] > day) {
          tmp = 0;
          continue;
        }

        ++tmp;

        if (tmp == k) {
          ++cnt;
          tmp = 0;
        }
      }

      return cnt;
    };

    int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
    while (l < r) {
      int mid = (r - l) / 2 + l;
      if(func(mid) < m) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l;
  }
};
// @lc code=end

