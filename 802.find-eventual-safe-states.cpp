/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    set<int> safe_nodes;

    // terminal nodes
    for (int i = 0; i < n; ++i)
      if (graph[i].size() == 0) safe_nodes.insert(i);

    // find safe nodes
    int last = 0;
    while (safe_nodes.size() > last) {
      last = safe_nodes.size();

      for (int i = 0; i < n; ++i) {
        if (safe_nodes.count(i)) continue;

        int cnt = 0;
        for (int node : graph[i]) {
          if (safe_nodes.count(node)) ++cnt;
        }

        if (cnt == graph[i].size()) safe_nodes.insert(i);
      }
    }

    return {safe_nodes.begin(), safe_nodes.end()};
  }
};
// @lc code=end

