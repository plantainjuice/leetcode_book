/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
 public:
  bool canCross(vector<int>& S) {
    int n = S.size();
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0; i < n; i++) mp[S[i]].insert(0);

    mp[S[0]].insert(1);

    for (int i = 0; i < n; i++) {
      for (int jump : mp[S[i]]) {
        if (jump <= 0) continue;

        int pos = S[i] + jump;

        if (pos == S[n - 1]) return true;

        if (mp.count(pos)) {
          mp[pos].insert(jump - 1);
          mp[pos].insert(jump);
          mp[pos].insert(jump + 1);
        }
      }
    }

    return false;
  }
};
// @lc code=end
