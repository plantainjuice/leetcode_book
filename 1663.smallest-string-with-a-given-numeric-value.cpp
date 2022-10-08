/*
 * @lc app=leetcode id=1663 lang=cpp
 *
 * [1663] Smallest String With A Given Numeric Value
 */

// @lc code=start
class Solution {
 public:
  string getSmallestString(int n, int k) {
    string s(n, 'a');
    k -= n;

    for (int i = n - 1; i >= 0; --i) {
      if (k == 0) break;

      int c = k > 25 ? 25 : k;

      s[i] += c;
      k -= c;
    }

    return s;
  }
};
// @lc code=end

