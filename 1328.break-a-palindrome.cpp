/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
 public:
  string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    if(n <= 1) return "";

    for (int i = 0; i < n / 2; ++i) {
      char c = palindrome[i];

      if (c == 'a') continue;

      palindrome[i] = 'a';
      return palindrome;
    }

    palindrome[n-1] = 'b';

    return palindrome;
  }
};
// @lc code=end

