/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
  int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;

    function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
      if (node == nullptr) return;

      if (low <= node->val && node->val <= high) sum += node->val;

      if (low <= node->val) dfs(node->left);

      if (node->val <= high) dfs(node->right);
    };

    dfs(root);

    return sum;
  }
};
// @lc code=end
