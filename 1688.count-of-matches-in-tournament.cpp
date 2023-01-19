/*
 * @lc app=leetcode id=1688 lang=cpp
 *
 * [1688] Count of Matches in Tournament
 */

// @lc code=start
class Solution {
 public:
  int numberOfMatches(int n) {
    int total = 0;

    while (n > 1) {
      total += n / 2;

      if (n % 2 == 0)
        n /= 2;
      else
        n = n / 2 + 1;
    }

    return total;
  }
};
// @lc code=end

