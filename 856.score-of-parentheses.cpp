/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
 public:
  int scoreOfParentheses(string s) {
    stack<int> st;
    int score = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        // save context
        st.push(score);
        score = 0;
      } else {
        // recover context
        int top = st.top();
        st.pop();

        // just a pair `()`
        if (score == 0) {
          score = top + 1;
        } else {
          score = top + 2 * score;
        }
      }
    }
    return score;
  }
};
// @lc code=end

