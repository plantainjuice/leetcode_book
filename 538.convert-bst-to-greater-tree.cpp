/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
  TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* node = new TreeNode(0);
    node->right = convertBST(root->right);

    sum_ += root->val;
    node->val = sum_;

    node->left = convertBST(root->left);


    return node;
  }

 private:
  int sum_ = 0;
};
// @lc code=end

