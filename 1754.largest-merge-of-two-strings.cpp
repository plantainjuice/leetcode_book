/*
 * @lc app=leetcode id=1754 lang=cpp
 *
 * [1754] Largest Merge Of Two Strings
 */

// @lc code=start
class Solution {
 public:
  string largestMerge(string word1, string word2) {
    int i = 0, j = 0;
    int m = word1.size();
    int n = word2.size();

    string ans = "";
    while (i < m && j < n) {
      if (word1.substr(i) > word2.substr(j))
        ans += word1[i++];
      else
        ans += word2[j++];
    }

    while (i < m) ans += word1[i++];
    while (j < n) ans += word2[j++];

    return ans;
  }
};
// @lc code=end

