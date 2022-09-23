/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->val) root->left = deleteNode(root->left, key);

    if (key > root->val) root->right = deleteNode(root->right, key);

    if (key == root->val) {
      if (root->left == nullptr && root->right == nullptr) {
        // delete root;
        return nullptr;
      }

      if (root->left == nullptr) return root->right;

      if (root->right == nullptr) return root->left;

      TreeNode* left = root->left;
      TreeNode* right = root->right;
      TreeNode* left_most = peakLeftMostChild(root->right);

      left_most->left = left;

      // delete root;
      return right;
    }

    return root;
  }

 private:
  TreeNode* peakLeftMostChild(TreeNode* cur) {
    if (cur->left == nullptr) {
      return cur;
    }
    return peakLeftMostChild(cur->left);
  }
};
// @lc code=end

