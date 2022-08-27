/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int calculate(string s) {
    vector<int> nums;
    char op = '+';
    int cur = 0;
    int pos = 0;
    while (pos < s.size()) {
        if (s[pos] == ' ') {
            ++pos;
            continue;
        }

        while (pos < s.size() && isdigit(s[pos])) {
          cur = cur * 10 + (s[pos++] - '0');
        }

        if (op == '+' || op == '-') {
          int sign = op == '+' ? 1 : -1;
          nums.push_back(sign * cur);
        } else if (op == '*') {
          nums.back() *= cur;
        } else if (op == '/') {
          nums.back() /= cur;
        }

        cur = 0;
        op = s[pos++];
    }

    return accumulate(nums.begin(), nums.end(), 0);
  }
};
// @lc code=end

