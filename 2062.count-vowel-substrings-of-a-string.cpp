/*
 * @lc app=leetcode id=2062 lang=cpp
 *
 * [2062] Count Vowel Substrings of a String
 */

// @lc code=start
class Solution {
 public:
  int countVowelSubstrings(string word) {
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    auto is_vowel_str = [&](int i, int j) -> bool {
      if (j - i < 4) return false;

      unordered_map<char, int> m;
      for (int k = i; k <= j; ++k) {
        if (vowels.count(word[k]) == 0) return false;

        m[word[k]] = 1;
      }

      for (char v : vowels)
        if (m[v] == 0) return false;

      return true;
    };

    int num = 0;

    for (int i = 0; i < word.size(); ++i)
      for (int j = i; j < word.size(); ++j)
        if (is_vowel_str(i, j)) ++num;

    return num;
  }
};
// @lc code=end
