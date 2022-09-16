/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int n5 = 0, n10 = 0, n20 = 0;  // incomes

    for (int b : bills) {
      if (b == 5) {
        ++n5;
      } else if (b == 10) {
        if (n5 == 0) return false;
        ++n10;
        --n5;
      } else {
        if (n10 > 0 && n5 > 0) {
          --n10;
          --n5;
        } else if (n5 >= 3) {
          n5 -= 3;
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
// @lc code=end

