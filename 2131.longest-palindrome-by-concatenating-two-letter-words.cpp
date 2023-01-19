/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
 public:
  int longestPalindrome(vector<string>& words) {
    vector<vector<int>> M(26, vector<int>(26, 0));

    // 1. count
    for (auto& w : words) ++M[w[0] - 'a'][w[1] - 'a'];

    // 2. find pair
    int odd_pair = 0;
    int even_pair = 0;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (i == j) {
          // is even
          if (M[i][j] % 2 == 0)
            even_pair += M[i][j];
          else {
            if (M[i][j] > odd_pair) {
              even_pair += max(0, odd_pair - 1);
              odd_pair = M[i][j];
            } else {
              even_pair += M[i][j] - 1;
            }
          }
        } else {
          even_pair += min(M[i][j], M[j][i]) * 2;
        }
      }
    }

    return (odd_pair + even_pair) * 2;
  }
};
// @lc code=end

