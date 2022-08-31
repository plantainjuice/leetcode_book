/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int excess_left = 0, excess_right = 0;
    for (const char c : s) {
      if (c == '(')
        ++excess_left;

      else if (c == ')') {
        if (excess_left == 0)
          excess_right++;
        else
          excess_left--;
      }
    }

    // remove the duplicate cases
    unordered_set<string> solutions;
    dfs(s, 0, 0, excess_left, excess_right, "", solutions);
    return {solutions.begin(), solutions.end()};
  }

 private:
  void dfs(const string& s, size_t pos, int opened_left_bracket, int excess_left, int excess_right, string solution, unordered_set<string>& solutions) {
    if (pos == s.size()) {
      if (opened_left_bracket == 0 && excess_left == 0 && excess_right == 0)
        solutions.insert(solution);
    } else if (s[pos] == '(') {
      if (excess_left > 0)
        dfs(s, pos + 1, opened_left_bracket, excess_left - 1, excess_right, solution, solutions);

      dfs(s, pos+1, opened_left_bracket + 1, excess_left, excess_right, solution + '(', solutions);
    } else if (s[pos] == ')') {
      if (excess_right > 0)
        dfs(s, pos + 1, opened_left_bracket, excess_left, excess_right - 1, solution, solutions);

      if (opened_left_bracket > 0)
        dfs(s, pos + 1, opened_left_bracket - 1, excess_left, excess_right, solution + ')', solutions);
    } else {
        dfs(s, pos + 1, opened_left_bracket, excess_left, excess_right, solution + s[pos], solutions);
    }
  }
};
// @lc code=end

