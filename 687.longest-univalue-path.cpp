/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
  int longestUnivaluePath(TreeNode* root) {
    longest_ = 0;
    walk(root);
    return longest_;
  }

 private:
  int longest_;

  int walk(TreeNode* root) {
    if (root == nullptr) return 0;

    int pl = 0;
    int pr = 0;

    int l = walk(root->left);
    if (root->left && root->val == root->left->val) {
      pl = l + 1;
    }

    int r = walk(root->right);
    if (root->right && root->val == root->right->val) {
      pr = r + 1;
    }

    longest_ = max(longest_, pl + pr);

    return max(pl, pr);
  }
};
// @lc code=end

