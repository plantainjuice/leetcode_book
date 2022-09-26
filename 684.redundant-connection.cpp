/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start

// disjoint union set
class DUS {
 public:
  DUS() : father_(1001, 0) {
    for (int i = 1; i <= 1000; ++i)
      father_[i] = i;
  };

  int find(int u) {
    if (father_[u] == u)
      return u;

    father_[u] = find(father_[u]);
    return father_[u];
  }

  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return ;
    father_[v] = u;
  }

  bool same(int u, int v) { return find(u) == find(v); }

 private:
  vector<int> father_;
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DUS dus;

    for (vector<int>& e : edges) {
      if (dus.same(e[0], e[1])) return e;
      dus.join(e[0], e[1]);
    }

    return {};
  }
};
// @lc code=end

