/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <unordered_set>

class Solution {
public:
    string reverseVowels(string s) {
      const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                          'A', 'E', 'I', 'O', 'U'};

      int l = 0, h = s.size() - 1;
      while (l < h ) {
        while (vowels.count(s[l]) == 0 && l < h) ++l;
        while (vowels.count(s[h]) == 0 && l < h) --h;

        swap(s[l], s[h]);
        ++l;
        --h;
      }

      return s;
    }
};
// @lc code=end

