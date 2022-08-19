/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
#include <unordered_map>
#include <sstream>

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long long n = numerator, d = denominator;
    if (n == 0 || d == 0) return "0";

    stringstream ss1, ss2;

    if (n > 0 && d < 0 || n < 0 && d > 0) {
      ss1 << "-";
      n = abs(n);
      d = abs(d);
    }

    ss1 << n / d;

    long long r = n % d;

    bool has_loop = false;
    int loop_start = 0;
    int count = 0;

    if (r) {
      n = r;
      ss1 << ".";
      unordered_map<int, int> recurse_pos;
      recurse_pos[r] = 0;

      while (r) {
        n = n * 10;
        r = n % d;
        ss2 << n / d;
        n = r;

        if (r && recurse_pos.count(r)) {
          has_loop = true;
          loop_start = recurse_pos[r];
          break;
        }

        recurse_pos[r] = ++count;
      }

      if (has_loop) {
        string s2 = ss2.str();
        ss1 << s2.substr(0, loop_start) << "(" << s2.substr(loop_start) << ")";
      } else {
        ss1 << ss2.str();
      }
    }

    return ss1.str();
  }
};
// @lc code=end

