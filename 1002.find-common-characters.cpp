/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> letter_cnt(26, 0);

    for (char c : words[0]) letter_cnt[c - 'a']++;

    for (const string& w : words) {
      // 1. get count
      vector<int> t(26, 0);
      for (char c : w) t[c - 'a']++;

      // 2. merge
      for (int i = 0; i < 26; ++i) {
        letter_cnt[i] = min(letter_cnt[i], t[i]);
      }
    }

    vector<string> ans;
    for (int i = 0; i < 26; ++i) {
      while (letter_cnt[i]--) {
        string s = "";
        s += (char)(i + 'a');
        ans.push_back(s);
      }
    }

    return ans;
  }
};
// @lc code=end

