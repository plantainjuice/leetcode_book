/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
 public:
  // vector<int> partitionLabels(string s) {
  vector<int> partitionLabels(const string& s) {
    int hash[26] = {0};
    for (int i = 0; i < s.size(); ++i) hash[s[i] - 'a'] = i;

    vector<int> ans;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); ++i) {
      right = max(right, hash[s[i] - 'a']);
      if (i == right) {
        ans.push_back(i - left + 1);
        left = i + 1;
      }
    }

    return ans;
  }
};
// @lc code=end

