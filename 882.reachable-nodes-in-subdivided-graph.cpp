/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */

// @lc code=start
class Solution {
 public:
  int reachableNodes(vector<vector<int>>& E, int M, int N) {
    // 1. build graph
    unordered_map<int, unordered_map<int, int>> G;
    for (auto& v : E) G[v[0]][v[1]] = G[v[1]][v[0]] = v[2];

    // 2. Dijkstra
    unordered_map<int, int> V;
    priority_queue<pair<int, int>> Q;
    Q.push({M, 0});

    while (Q.size()) {
      int moves = Q.top().first, i = Q.top().second;
      Q.pop();

      if (V.count(i)) continue;

      V[i] = moves;
      for (auto j : G[i]) {
        int moves2 = moves - j.second - 1;
        if (!V.count(j.first) && moves2 >= 0) Q.push({moves2, j.first});
      }
    }

    // 3. cal
    int ans = V.size();
    for (auto v : E) {
      int a = V.find(v[0]) == V.end() ? 0 : V[v[0]];
      int b = V.find(v[1]) == V.end() ? 0 : V[v[1]];
      ans += min(a + b, v[2]);
    }
    return ans;
  }
};
// @lc code=end
