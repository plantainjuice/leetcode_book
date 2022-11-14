/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197851/C%2B%2B-DFS
class Solution {
 public:
  int removeStones(vector<vector<int>>& stones) {
    // 1. build graph
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;

    for (vector<int>& s : stones) {
      rows[s[0]].push_back(s[1]);
      cols[s[1]].push_back(s[0]);
    }

    // 2. dfs
    unordered_set<int> v_rows;
    function<int(int)> dfs = [&](int row) -> int {
      int res = 0;

      // not visited
      if (v_rows.insert(row).second) {
        res += rows[row].size();

        for (int col : rows[row]) {
          for (int r : cols[col]) {
            res += dfs(r);
          }
        }
      }

      return res;
    };

    int ans = 0;
    for (auto r : rows) ans += max(0, dfs(r.first) - 1);

    return ans;
  }
};
// @lc code=end
