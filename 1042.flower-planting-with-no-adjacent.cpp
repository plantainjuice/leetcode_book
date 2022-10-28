/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    // 0: unknown
    // 1: flower 1
    // 2: flower 2
    // 3: flower 3
    // 4: flower 4
    vector<int> colors(n);

    // build graph
    vector<vector<int>> graph(n);
    for (auto& p : paths) {
      int i = p[0] - 1;
      int j = p[1] - 1;
      graph[i].push_back(j);
      graph[j].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
      vector<bool> used(5);
      for (int neigh : graph[i]) used[colors[neigh]] = true;
      for (int f = 1; f <= 4; ++f)
        if (!used[f]) {
          colors[i] = f;
          break;
        }
    }

    return colors;
  }
};
// @lc code=end

