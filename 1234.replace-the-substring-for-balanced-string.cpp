/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
class Solution {
 public:
  int balancedString(string s) {
    map<char, int> cnt;
    for (auto& c : s) ++cnt[c];

    int ans = INT_MAX;

    int sz = s.size();
    int i = 0, j = 0;

    // [i, j)
    while (i < sz && j <= sz) {
      if (cnt['Q'] <= sz / 4 && cnt['W'] <= sz / 4 && cnt['E'] <= sz / 4 &&
          cnt['R'] <= sz / 4) {
        ans = min(ans, j - i);
        ++cnt[s[i++]];
      } else {
        --cnt[s[j++]];
      }
    }

    return ans;
  }
};
// @lc code=end

