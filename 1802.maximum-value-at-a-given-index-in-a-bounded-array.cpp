/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution {
 public:
  int maxValue(int n, int index, int maxSum) {
    auto least = [&](int guess) -> long {
      long sum = 0;
      sum += n * (long)guess;

      // left part (triangle)
      long l_len = min(index, guess - 1);
      sum -= (l_len) * (l_len + 1) / 2;

      // right part (triangle)
      long r_len = min(n - index - 1, guess - 1);
      sum -= (r_len) * (r_len + 1) / 2;

      if (l_len == guess - 1) sum -= (guess - 1) * (index - l_len);

      if (r_len == guess - 1) sum -= (guess - 1) * (n - index - 1 - r_len);

      return sum;
    };

    int l = 1, h = maxSum;
    while (l < h) {
      int mid = (l + h) / 2 + 1;
      if (least(mid) > maxSum)
        h = mid - 1;
      else
        l = mid;
    }

    return l;
  }
};
// @lc code=end
