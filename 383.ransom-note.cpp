/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
 public:
//   bool canConstruct(string ransomNote, string magazine) {
  bool canConstruct(const string& ransomNote, const string& magazine) {
    vector<int> map(26, 0);

    for (const char c : magazine) map[c - 'a'] += 1;

    for (const char c : ransomNote) {
      if (map[c - 'a'] == 0) return false;
      map[c - 'a'] -= 1;
    }

    return true;
  }
};
// @lc code=end

