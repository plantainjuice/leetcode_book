/*
 * @lc app=leetcode id=2287 lang=cpp
 *
 * [2287] Rearrange Characters to Make Target String
 */

// @lc code=start
class Solution {
 public:
  int rearrangeCharacters(string s, string target) {
    vector<int> v1(26, 0), v2(26, 0);
    for (char c : target) ++v1[c - 'a'];
    for (char c : s) ++v2[c - 'a'];

    int cnt = INT_MAX;
    for (int i = 0; i < 26; ++i) {
      if (v1[i] == 0) continue;
      cnt = min(cnt, v2[i] / v1[i]);
    }

    return cnt;
  }
};
// @lc code=end
