/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
  int maxProduct(TreeNode* root) {
    constexpr int MOD = 1e9 + 7;

    // 1. build sum tree
    function<long(TreeNode*)> dfs = [&](TreeNode* node) -> long {
      if (node == nullptr) return 0;

      long l = dfs(node->left);
      long r = dfs(node->right);

      return node->val = (l + r + node->val);
    };

    long sum = dfs(root);

    // 2. find max product
    long max_product = 0;
    function<void(TreeNode*)> find = [&](TreeNode* node) -> void {
      if (node->left != nullptr) {
        long p = (sum - node->left->val) * node->left->val;
        max_product = max(max_product, p);

        find(node->left);
      }

      if (node->right != nullptr) {
        long r = (sum - node->right->val) * node->right->val;
        max_product = max(max_product, r);

        find(node->right);
      }
    };

    find(root);

    return max_product % MOD;
  }
};
// @lc code=end
