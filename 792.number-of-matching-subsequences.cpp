/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> dict(26);

    for (int i = 0; i < s.size(); ++i) dict[s[i] - 'a'].push_back(i);

    int ans = 0;
    for (string& word : words) {
      bool found = true;
      int x = -1;

      for (char c : word) {
        vector<int>& index = dict[c - 'a'];

        auto it = upper_bound(index.begin(), index.end(), x);

        if (it == index.end()) {
          found = false;
          break;
        }

        x = *it;
      }

      if (found) ++ans;
    }

    return ans;
  }
};
// @lc code=end
