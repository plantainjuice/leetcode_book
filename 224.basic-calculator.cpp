/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    function<int(int&)> eval = [&] (int& pos) {
        int ret = 0;
        int val = 0;
        int sign = 1;

        while(pos < s.size()) {
            const char ch = s[pos];
            if (isdigit(ch)) {
                val = val * 10 + (s[pos++] - '0');
            } else if (ch == '+' || ch  == '-') {
              ret += sign * val;
              val = 0;
              sign = ch == '+' ? 1 : -1;
              ++pos;
            } else if (ch == '(') {
              val = eval(++pos);
            } else if (ch == ')') {
              ++pos;
              break;
            } else {
              ++pos;
            }
        }

        ret += sign * val;
        return ret;
    };

    int pos = 0;
    return eval(pos);
  }
};
// @lc code=end

