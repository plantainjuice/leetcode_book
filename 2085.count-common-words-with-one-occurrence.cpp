/*
 * @lc app=leetcode id=2085 lang=cpp
 *
 * [2085] Count Common Words With One Occurrence
 */

// @lc code=start
class Solution {
 public:
  int countWords(vector<string>& W1, vector<string>& W2) {
    map<string, int> mp1;
    map<string, int> mp2;

    for (const string& s : W1) mp1[s]++;

    for (const string& s : W2) mp2[s]++;

    int cnt = 0;
    for (const string& s : W2) {
      if (mp1.find(s) == mp1.end()) continue;

      if (mp1[s] != 1 || mp2[s] != 1) continue;

      ++cnt;
    }

    return cnt;
  }
};
// @lc code=end

