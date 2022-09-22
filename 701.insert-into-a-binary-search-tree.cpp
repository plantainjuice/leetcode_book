/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);

    traversal(root, val);

    return root;
  }

 private:
  TreeNode* parent_;
  void traversal(TreeNode* cur, int val) {
    if (cur == nullptr) {
      TreeNode* node = new TreeNode(val);
      if (val > parent_->val)
        parent_->right = node;
      else
        parent_->left = node;
      return;
    }

    parent_ = cur;
    if (cur->val > val) traversal(cur->left, val);
    if (cur->val < val) traversal(cur->right, val);
  }
};
// @lc code=end

