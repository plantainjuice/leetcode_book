/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    auto get_sum = [](int n) -> int {
      int sum = 0;
      while (n) {
        int i = n % 10;
        n /= 10;

        sum += i * i;
      }
      return sum;
    };

    set<int> s;
    while (n != 1) {
      n = get_sum(n);
      if (s.count(n) != 0) return false;
      s.insert(n);
    }

    return true;
  }
};
// @lc code=end

