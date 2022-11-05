/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

// @lc code=start
class Solution {
 public:
  bool parseBoolExpr(const string& expr) {
    if (expr.size() == 1) return expr == "t" ? true : false;

    if (expr[0] == '!') return !parseBoolExpr(expr.substr(2, expr.size() - 3));

    bool is_and = expr[0] == '&' ? true : false;
    bool res = is_and;
    int l = 2, h = 2;  // skip 2 char
    int cnt = 0;
    for (; h < expr.size(); ++h) {
      if (expr[h] == '(') ++cnt;
      if (expr[h] == ')') --cnt;

      if (h == expr.size() - 1 || (expr[h] == ',' && cnt == 0)) {
        if (is_and)
          res &= parseBoolExpr(expr.substr(l, h - l));
        else
          res |= parseBoolExpr(expr.substr(l, h - l));
        l = h + 1;
      }
    }

    return res;
  }
};
// @lc code=end

