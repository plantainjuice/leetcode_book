/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return nullptr;

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    if (low <= root->val && root->val <= high) return root;

    if (low > root->val) return root->right;

    if (high < root->val) return root->left;

    return root;
  }
};
// @lc code=end

