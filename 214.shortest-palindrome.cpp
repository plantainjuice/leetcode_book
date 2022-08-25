/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        const string r(s.rbegin(), s.rend());

        int n = s.size();

        for (int i = 0; i < n; ++i) {
          if (s.compare(0, n - i, r, i, n - i) == 0) {
            return r.substr(0, i) + s;
          }
        }

        return s;
    }
};
// @lc code=end

