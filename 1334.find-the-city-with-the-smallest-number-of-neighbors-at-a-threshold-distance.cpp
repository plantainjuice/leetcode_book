/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    constexpr int INF_DIS = 1e4 + 1;
    vector<vector<int>> graph(n, vector<int>(n, INF_DIS));

    // 1. build graph
    for (auto e : edges) graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];

    // 2. find weight
    for(int i = 0; i < n; ++i) graph[i][i] = 0;

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    // find the smallest one
    int ans = 0;
    int cnt = INF_DIS;
    for (int i = 0; i < n; ++i) {
      int c = 0;
      for (int j = 0; j < n; ++j) {
        if (graph[i][j] <= distanceThreshold) ++c;
      }

      if(c <= cnt) {
        ans = i;
        cnt = c;
      }
    }

    return ans;
  }
};
// @lc code=end

