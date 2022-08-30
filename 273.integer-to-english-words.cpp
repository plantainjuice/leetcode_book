/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
#include <string>

constexpr char* kUnder20[] = {"One",       "Two",      "Three",   "Four",
                              "Five",      "Six",      "Seven",   "Eight",
                              "Nine",      "Ten",      "Eleven",  "Twelve",
                              "Thirteen",  "Fourteen", "Fifteen", "Sixteen",
                              "Seventeen", "Eighteen", "Nineteen"};

constexpr char* kUnder100[] = {"Twenty", "Thirty",  "Forty", "Fifty",
                               "Sixty",  "Seventy", "Eighty", "Ninety"};

constexpr char* kHTMB[] = {"Hundred", "Thousand", "Million", "Billion"};
constexpr int kUnit[] = {100, 1000, 1000 * 1000, 1000 * 1000 * 1000};

class Solution {
 public:
  string numberToWords(int num) {
    if (num == 0) return "Zero";
    return convert(num).substr(1);  // ignore first " "
  }

  string convert(int num) {
    if (num == 0) return "";

    if (num < 20) return string(" ") + kUnder20[num - 1];

    if (num < 100)
      return string(" ") + kUnder100[num / 10 - 2] + convert(num % 10);

    for (int i = 3; i >= 0; --i) {
      if (num >= kUnit[i])
        return convert(num / kUnit[i]) + " " + kHTMB[i] + convert(num % kUnit[i]);
    }

    return "";
  }
};
// @lc code=end

