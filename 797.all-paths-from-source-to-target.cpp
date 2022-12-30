/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int target = graph.size() - 1;

    queue<pair<int, vector<int>>> q;
    q.push({0, {0}});

    vector<vector<int>> ans;
    while (!q.empty()) {
      pair<int, vector<int>> p = q.front();
      q.pop();

      if (p.first == target) {
        ans.push_back(p.second);
        continue;
      }

      for (int next : graph[p.first]) {
        vector<int> path = p.second;
        path.push_back(next);
        q.push({next, path});
      }
    }

    return ans;
  }
};
// @lc code=end

