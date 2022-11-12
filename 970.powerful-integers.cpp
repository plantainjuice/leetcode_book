/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */

// @lc code=start
class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    set<int> ans;

    for (int i = 1; i < bound; i *= x) {
      for (int j = 1; i + j <= bound; j *= y) {
        ans.insert(i + j);
        if (y == 1) break;
      }

      if (x == 1) break;
    }

    return {ans.begin(), ans.end()};
  }
};
// @lc code=end

