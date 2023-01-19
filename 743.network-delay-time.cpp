/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // 1. build graph
    vector<vector<vector<int>>> graph(n);

    for (auto& edge : times) {
      int v1 = edge[0] - 1;
      int v2 = edge[1] - 1;
      int w = edge[2];
      graph[v1].push_back({v2, w});
    }

    // 2. bfs search
    queue<pair<int, int>> Q;
    vector<int> V(n, INT_MAX);
    Q.push({k - 1, 0});
    V[k - 1] = 0;

    while (!Q.empty()) {
      int l = Q.size();

      while (l--) {
        pair<int, int> kv = Q.front();
        Q.pop();

        int node = kv.first;
        int time = kv.second;

        for (auto& e : graph[node]) {
          if (time + e[1] >= V[e[0]]) continue;

          V[e[0]] = time + e[1];
          Q.push({e[0], V[e[0]]});
        }
      }
    }

    int min_t = 0;
    for (int i = 0; i < n; ++i) {
      if (V[i] == INT_MAX) return -1;

      min_t = max(min_t, V[i]);
    }

    return min_t;
  }
};
// @lc code=end

