/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    int n = 0;
    unordered_set<int> u;
    unordered_map<int, int> lose_cnt;
    for (vector<int>& m : matches) {
      u.insert(m[0]);
      u.insert(m[1]);

      ++lose_cnt[m[1]];
    }

    vector<vector<int>> ans(2);
    for (int i : u) {
      auto iter = lose_cnt.find(i);

      if (iter == lose_cnt.end())
        ans[0].push_back(i);
      else if (iter->second == 1)
        ans[1].push_back(i);
    }

    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());

    return ans;
  }
};
// @lc code=end
