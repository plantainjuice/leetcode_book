/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
 public:
  bool halvesAreAlike(string s) {
    int n = s.size();

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int p1 = 0;
    int p2 = 0;

    int i = 0, j = n / 2;
    while (i < n / 2) {
      if (vowels.count(s[i])) ++p1;
      if (vowels.count(s[j])) ++p2;

      ++i;
      ++j;
    }

    return p1 == p2;
  }
};
// @lc code=end
