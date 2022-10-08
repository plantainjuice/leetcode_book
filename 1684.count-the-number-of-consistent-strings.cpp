/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> m(26, false);
    for (char c : allowed) m[c - 'a'] = true;

    int ans = words.size();
    for (const string& w : words)
      for (char c : w)
        if (m[c - 'a'] == false) {
          ans--;
          break;
        }

    return ans;
  }
};
// @lc code=end

