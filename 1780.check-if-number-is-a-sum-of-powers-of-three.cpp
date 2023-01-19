/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
class Solution {
 public:
  bool checkPowersOfThree(int n) {
    // table
    vector<int> table = {4782969, 1594323, 531441, 177147, 59049,
                         19683,   6561,    2187,   729,    243,
                         81,      27,      9,      3,      1};

    for (int power : table) {
      if (n >= power) n -= power;
    }

    return n == 0;
  }
};
// @lc code=end
