/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start

#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      std::stack<long> s;

      for (const auto& token : tokens) {
        if (isdigit(token.back())) {
            s.push(stoi(token.c_str()));
        } else {
          long op2 = s.top(); s.pop();
          long op1 = s.top(); s.pop();

          long res = 0;
          if (token == "+") {
            res = op1 + op2;
          } else if (token == "-") {
            res = op1 - op2;
          } else if (token == "*") {
            res = op1 * op2;
          } else if (token == "/") {
            res = op1 / op2;
          }
          s.push(res);
        }
      }

      return s.top();
    }
};
// @lc code=end

