/*
 * @lc app=leetcode id=2311 lang=cpp
 *
 * [2311] Longest Binary Subsequence Less Than or Equal to K
 */

// @lc code=start
class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int val = 0, cnt = 0, pow = 1;
    for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
      if (s[i] == '1') {
        ++cnt;
        val += pow;
      }
      pow <<= 1;
    }
    return count(begin(s), end(s), '0') + cnt;
  }
};
// @lc code=end

