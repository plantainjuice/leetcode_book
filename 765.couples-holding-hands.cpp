/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    auto is_couple = [](int l, int r) -> bool { return (l / 2) == (r / 2); };
    auto get_couple = [](int n) -> int { return 2 * (n / 2) + (1 - n % 2); };

    unordered_map<int, int> m;
    for (int i = 0; i < row.size(); ++i) m[row[i]] = i;

    int swap = 0;
    for (int i = 0; i < row.size(); i += 2) {
      if (is_couple(row[i], row[i + 1])) continue;

      int c = get_couple(row[i]);
      m[row[i + 1]] = m[c];
      std::swap(row[i + 1], row[m[c]]);

      ++swap;
    }

    return swap;
  }
};
// @lc code=end
