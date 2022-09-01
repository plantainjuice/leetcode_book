/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> cnt(256, 0);
    vector<bool> visited(256, false);

    for (const char c : s) ++cnt[c];

    string ans = "0";
    for (const char c : s) {
      --cnt[c];
      if (visited[c]) continue;

      while (c < ans.back() && cnt[ans.back()] > 0) {
        visited[ans.back()] = false;
        ans.pop_back();
      }

      ans += c;
      visited[c] = true;
    }

    return ans.substr(1);
  }
};
// @lc code=end

