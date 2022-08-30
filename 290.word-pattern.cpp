/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> m1;  // pattern -> word
    unordered_map<string, char> m2;  // word -> pattern
    vector<string> words = split(s);

    if (pattern.size() != words.size()) return false;

    for (int i = 0; i < pattern.size(); ++i) {
      const char c = pattern[i];
      const string& w = words[i];

      if (m1.find(c) == m1.end() && m2.find(w) == m2.end()) {
        m1[c] = w;
        m2[w] = c;
        continue;
      }

      if (m1[c] != w) return false;
      if (m2[w] != c) return false;
    }

    return true;
  }

 private:
  vector<string> split(const string& s) {
    vector<string> r;
    int last_pos = 0;
    int pos = 0;
    while (pos < s.size()) {
      if (s[pos] == ' ') {
        r.push_back(s.substr(last_pos, pos - last_pos));
        last_pos = pos + 1;
      }
      ++pos;
    }

    r.push_back(s.substr(last_pos, pos - last_pos));

    return r;
  }
};
// @lc code=end
