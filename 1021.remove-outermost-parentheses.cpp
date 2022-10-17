/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans;
    int left_bracket = 0;

    for (char c : s) {
      if (c == '(') {
        left_bracket++;
        if (left_bracket == 1)
          continue;
        else
          ans += c;
      } else {
        left_bracket--;
        if (left_bracket == 0)
          continue;
        else
          ans += c;
      }
    }

    return ans;
  }
};
// @lc code=end

