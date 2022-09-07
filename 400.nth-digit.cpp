/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
      long num = n;

      int real = 0; // the num

      long base = 9;
      long base_width = 1;
      while(num > base * base_width) {
        num -= base * base_width;

        real += base;

        base *= 10;
        base_width += 1;
      }

      real += (num - 1) / (base_width) + 1;
      int nth = num % base_width == 0 ? base_width : num % base_width;

      return get_nth_of_num(real, nth);
    }
private:
  int get_nth_of_num(int num, int nth) {
    string s = to_string(num);
    return stoi(s.substr(nth - 1, 1));
  }
};
// @lc code=end

