/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    // union set
    vector<int> ds(n);
    iota(ds.begin(), ds.end(), 0);

    function<int(int)> find = [&](int i) -> int {
      return (ds[i] == i) ? i : ds[i] = find(ds[i]);
    };

    for (int i = 0; i < connections.size(); ++i) {
      int c1 = connections[i][0];
      int c2 = connections[i][1];

      if (find(c1) != find(c2)) 
        ds[find(c2)] = find(c1);
    }

    set<int> s;
    for (int i = 0; i < n; ++i)
        s.insert(find(i));

    return s.size() - 1;
  }
};
// @lc code=end

