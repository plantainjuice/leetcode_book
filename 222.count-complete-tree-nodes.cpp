/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh == rh)
      return (1 << lh) + countNodes(root->right);
    else
      return (1 << rh) + countNodes(root->left);
    return 0;
  }

 private:
  // can only used for complete-binary tree
  int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + height(root->left);
  };
};
// @lc code=end

