/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
// https://leetcode.com/problems/sum-of-distances-in-tree/solutions/130583/c-java-python-pre-order-and-post-order-dfs-o-n/
class Solution {
 public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<unordered_set<int>> tree(N);
    vector<int> ans(N), count(N, 1);

    // 1. build tree
    for (auto& e : edges) {
      tree[e[0]].insert(e[1]);
      tree[e[1]].insert(e[0]);
    }

    // 2. post order dfs
    function<void(int, int)> dfs = [&](int root, int pre) -> void {
      for (auto i : tree[root]) {
        if (i == pre) continue;

        dfs(i, root);
        count[root] += count[i];
        ans[root] += ans[i] + count[i];
      }
    };

    // 3. pre order dfs
    function<void(int, int)> dfs2 = [&](int root, int pre) -> void {
      for (auto i : tree[root]) {
        if (i == pre) continue;

        ans[i] = (ans[root] - count[i]) + (N - count[i]);
        dfs2(i, root);
      }
    };

    dfs(0, -1);
    dfs2(0, -1);

    return ans;
  }
};
// @lc code=end
