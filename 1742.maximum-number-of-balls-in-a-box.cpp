/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

// @lc code=start
class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> cnt(46, 0);

    auto get_box = [](int n) -> int {
      int sum = 0;
      while (n) {
        sum += (n % 10);
        n /= 10;
      }
      return sum;
    };

    for (int n = lowLimit; n <= highLimit; ++n) {
      int box = get_box(n);
      ++cnt[box];
    }

    return *max_element(cnt.begin(), cnt.end());
  }
};
// @lc code=end
