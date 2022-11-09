/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    function<pair<TreeNode*, int>(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) -> pair<TreeNode*, int> {
      if (node == nullptr) return {node, depth};

      auto lp = dfs(node->left, depth + 1);
      auto rp = dfs(node->right, depth + 1);

      if (lp.second == rp.second) return {node, lp.second};

      if (lp.second > rp.second) return lp;

      return rp;
    };

    auto r = dfs(root, 0);
    return r.first;
  }
};
// @lc code=end
