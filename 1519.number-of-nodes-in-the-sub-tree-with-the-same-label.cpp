/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    // 1. build graph
    vector<vector<int>> graph(n);
    for (vector<int>& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    // 2. iterate
    vector<int> ans(n, 0);
    vector<bool> visited(n, false);

    function<map<char, int>(int)> dfs = [&](int node) -> map<char, int> {
      if (visited[node] == true) return {};
      visited[node] = true;

      map<char, int> res;
      ++res[labels[node]];

      for (int neigh : graph[node]) {
        map<char, int> r = dfs(neigh);
        for (auto kv : r) res[kv.first] += kv.second;
      }

      ans[node] = res[labels[node]];

      return res;
    };

    dfs(0);

    return ans;
  }
};
// @lc code=end
