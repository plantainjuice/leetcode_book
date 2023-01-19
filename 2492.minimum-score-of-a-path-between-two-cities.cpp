/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    // 1. build graph
    vector<vector<pair<int, int>>> graph(n + 1);

    for (vector<int>& r : roads) {
      graph[r[0]].push_back({r[1], r[2]});
      graph[r[1]].push_back({r[0], r[2]});
    }

    // 2. bfs
    int minimum = INT_MAX;
    unordered_set<int> v;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
      int l = q.size();

      while (l--) {
        int c = q.front();
        q.pop();

        // neighbor
        for (pair<int, int> neigh : graph[c]) {
          minimum = min(minimum, neigh.second);

          if (v.count(neigh.first)) continue;

          q.push(neigh.first);
          v.insert(neigh.first);
        }
      }
    }

    return minimum;
  }
};
// @lc code=end
