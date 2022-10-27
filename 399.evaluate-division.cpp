/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    int n = values.size();
    map<string, vector<pair<string, double>>> graph;

    // build graph
    for (int i = 0; i < n; ++i) {
      string a = equations[i][0];
      string b = equations[i][1];
      double v = values[i];
      graph[a].push_back({b, v});
      graph[b].push_back({a, 1 / v});
    }

    function<double(const string&, const string&, unordered_set<string>&)> dfs =
        [&](const string& src, const string& dst,
            unordered_set<string>& visited) -> double {
      if (graph.find(src) == graph.end()) return -1;
      if (src == dst) return 1;

      for (auto node : graph[src]) {
        if (visited.count(node.first)) continue;
        visited.insert(node.first);
        double res = dfs(node.first, dst, visited);
        if (res != -1) return res * node.second;
      }
      return -1;
    };

    vector<double> ans;
    for (int i = 0; i < queries.size(); ++i) {
      string a = queries[i][0];
      string b = queries[i][1];
      unordered_set<string> visited;
      ans.push_back(dfs(a, b, visited));
    }

    return ans;
  }
};
// @lc code=end

