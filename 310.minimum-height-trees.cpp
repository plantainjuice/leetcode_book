/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      // ans's size must >= 2, dealing with the edge case
      if(n <= 0) return {};
      if(n == 1) return {0};
      if(n == 2) return {0, 1};

      // Build the graph with adjacent list
      vector<set<int>> neighbors(n) ;
      for (const auto& e : edges) {
        neighbors[e[0]].insert(e[1]);
        neighbors[e[1]].insert(e[0]);
      }

      // find the first-layer leaves
      vector<int> leaves;
      for(int i = 0; i < n; ++i) {
        if (neighbors[i].size() == 1) leaves.push_back(i);
      }

      // trim by topology-way
      int remaining_nodes = n;
      while (remaining_nodes > 2) {
        remaining_nodes -= leaves.size();
        vector<int> new_leaves;

        while(leaves.size() > 0) {
          int leaf = leaves.back();
          leaves.pop_back();

          int neighbor = *(neighbors[leaf].begin());
          neighbors[neighbor].erase(leaf);
          if (neighbors[neighbor].size() == 1) {
            new_leaves.push_back(neighbor);
          }
        }

        leaves = move(new_leaves);
      }

      return leaves;
    }
};
// @lc code=end

