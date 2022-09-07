/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
 public:
  // https://leetcode.com/problems/sum-of-two-integers/discuss/2511049/C%2B%2B-oror-Explanation-oror-Keeping-it-simple-oror-0ms-Faster-than-100
  int getSum(int a, int b) {
    int sum = 0, c = 0;  // carry bit
    int x = 0, y = 0;

    for (int i = 0; i < 32; ++i) {
      x = a & 1; a = a >> 1;
      y = b & 1; b = b >> 1;

      sum = sum | (x ^ y ^ c) << i;
      c = (x & y | x & c | y & c);
    }

    return sum;
  }
};
// @lc code=end

