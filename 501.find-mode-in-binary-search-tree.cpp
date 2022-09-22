/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
  vector<int> findMode(TreeNode* root) {
    midTraversal(root);
    return modes_;
  }

 public:
  int max_count_ = 0;
  int count_ = 0;
  vector<int> modes_;
  TreeNode* pre_ = nullptr;

  void midTraversal(TreeNode* root) {
    if (root == nullptr) return;

    midTraversal(root->left);

    if (pre_ == nullptr)
      count_ = 1;
    else if (pre_->val == root->val)
      count_ += 1;
    else
      count_ = 1;

    pre_ = root;

    if (count_ == max_count_) {
      modes_.push_back(root->val);
    }

    if (count_ > max_count_) {
      max_count_ = count_;
      modes_.clear();
      modes_.push_back(root->val);
    }
    midTraversal(root->right);
  }
};
// @lc code=end

