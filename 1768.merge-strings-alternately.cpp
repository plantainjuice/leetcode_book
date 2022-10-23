/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
 public:
  // string mergeAlternately(string word1, string word2) {
  string mergeAlternately(const string& word1, const string& word2) {
    int n1 = word1.size(), n2 = word2.size();
    int i = 0, j = 0;

    string ans;

    int cnt = 0;
    while (i < n1 && j < n2) {
      if (cnt % 2 == 0)
        ans += word1[i++];
      else
        ans += word2[j++];

      ++cnt;
    }

    while(i != n1) ans += word1[i++];
    while(j != n2) ans += word2[j++];

    return ans;
  }
};
// @lc code=end

