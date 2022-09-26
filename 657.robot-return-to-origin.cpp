/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
 public:
  // bool judgeCircle(string moves) {
  bool judgeCircle(const string& moves) {
    int x = 0, y = 0;
    for (char c : moves) {
      if (c == 'U') ++y;
      if (c == 'D') --y;
      if (c == 'L') ++x;
      if (c == 'R') --x;
    }

    return (x == 0) && (y == 0);
  }
};
// @lc code=end

