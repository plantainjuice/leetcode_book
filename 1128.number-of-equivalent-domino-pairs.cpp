/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> mp;

    for (vector<int>& v : dominoes) {
      int id = 0;
      if (v[0] > v[1])
        id = (v[1] << 16) + v[0];
      else
        id = (v[0] << 16) + v[1];

      mp[id]++;
    }

    int ans = 0;

    for (auto& kv : mp) {
      int cnt = kv.second;
      if (cnt == 1) continue;

      // Cn-2
      ans += cnt * (cnt - 1) / 2;
    }

    return ans;
  }
};
// @lc code=end

