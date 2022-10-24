/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    ans_ = 0;

    dfs(root, distance);
    return ans_;
  }

 private:
  int ans_;
  vector<int> dfs(TreeNode* node, int d) {
    vector<int> p = {};
    if (node == nullptr) return {};

    // leaf
    if (node->left == nullptr && node->right == nullptr) {
      p.push_back(1);
      return p;
    }

    auto left = dfs(node->left, d);
    auto right = dfs(node->right, d);

    for (int l : left)
      for (int r : right)
        if (l + r <= d) ans_++;

    for (int l : left)
      if (l < d) p.push_back(l + 1);

    for (int r : right)
      if (r < d) p.push_back(r + 1);

    return p;
  }
};
// @lc code=end

