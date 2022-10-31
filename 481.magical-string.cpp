/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
class Solution {
 public:
  int magicalString(int n) {
    string S = "122";

    auto flip = [](char c) -> char {
      if (c == '1') return '2';

      // if c == '2'
      return '1'; 
    };

    int i = 2;
    while (S.size() < n)
      if (S[i++] == '1')
        S += string(1, flip(S.back()));
      else
        S += string(2, flip(S.back()));

    return count(S.begin(), S.begin() + n, '1');
  }
};
// @lc code=end

