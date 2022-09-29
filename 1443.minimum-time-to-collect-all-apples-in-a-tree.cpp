/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    visited_ = vector<bool>(n, false);
    buildGraph(edges);
    return dfs(0, 0, hasApple);
  }

 private:
  unordered_map<int, vector<int>> g_;  // graph
  vector<bool> visited_;   // mark visited

  void buildGraph (vector<vector<int>>& edges) {
    for(vector<int>& e : edges) {
      g_[e[0]].push_back(e[1]);
      g_[e[1]].push_back(e[0]);
    }
  }

  int dfs(int node, int curCost, vector<bool>& hasApple) {
    if(visited_[node] == true) return 0;

    visited_[node] = true;

    int childrenCost = 0;

    for (int child : g_[node]) {
      childrenCost += dfs(child, 2, hasApple);
    }

    if (childrenCost == 0 && hasApple[node] == false) return 0;

    return childrenCost + curCost;
  }
};
// @lc code=end

