/*
 * @lc app=leetcode id=2262 lang=cpp
 *
 * [2262] Total Appeal of A String
 */

// @lc code=start
class Solution {
 public:
  long long appealSum(string s) {
    long long ans = 0;
    int last[26] = {0};
    for (int l = 1; l <= s.size(); ++l) {
      last[s[l - 1] - 'a'] = l;

      for (int j : last) ans += j;
    }

    return ans;
  }
};
// @lc code=end

