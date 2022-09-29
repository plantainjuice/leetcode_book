/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

// @lc code=start
class Solution {
public:
    int kthFactor(int n, int k) {
      for(int d = 1; d <= n / 2; ++d)
        if (n % d == 0 && --k == 0) return d;

      return k == 1 ? n : -1;
    }
};
// @lc code=end

