/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
 public:
  int longestPath(vector<int>& parent, string s) {
    // 1. build child
    vector<vector<int>> child(s.size());
    for (int i = 1; i < parent.size(); ++i) child[parent[i]].push_back(i);

    int longest = 1;

    // 2. dfs find
    function<int(int)> dfs = [&](int node) -> int {
      if (child[node].size() == 0) return 1;
      int mx1 = 0, mx2 = 0;

      for (int neigh : child[node]) {
        int len = dfs(neigh);
        longest = max(longest, len);

        if (s[node] == s[neigh]) continue;

        if (len > mx1) {
          mx2 = mx1;
          mx1 = len;
        } else if (len > mx2) {
          mx2 = len;
        }
      }

      longest = max(longest, mx1 + mx2 + 1);

      return mx1 + 1;
    };

    dfs(0);

    return longest;
  }
};
// @lc code=end
