/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
 public:
  bool validPath(int N, vector<vector<int>>& E, int SRC, int DST) {
    if (SRC == DST) return true;

    // 1. build graph
    vector<vector<int>> G(N);
    for (vector<int>& e : E) {
      G[e[0]].push_back(e[1]);
      G[e[1]].push_back(e[0]);
    }

    // 2. dfs
    unordered_set<int> V;
    queue<int> Q;
    Q.push(SRC);
    V.insert(SRC);

    while (!Q.empty()) {
      int l = Q.size();

      while (l--) {
        int next = Q.front();
        Q.pop();

        for (int neigh : G[next]) {
          if (V.count(neigh)) continue;

          if (neigh == DST) return true;

          Q.push(neigh);
          V.insert(neigh);
        }
      }
    }

    return false;
  }
};
// @lc code=end
