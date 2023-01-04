/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks) ++cnt[t];

    auto minimum = [](int n) -> int {
      if (n == 1) return -1;

      if (n % 3 == 0) return n / 3;

      return n / 3 + 1;
    };

    int rounds = 0;
    for (pair<int, int> p : cnt) {
      int r = minimum(p.second);

      if (r == -1) return -1;

      rounds += r;
    }

    return rounds;
  }
};
// @lc code=end
