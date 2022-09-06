/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  int maxPathSum(TreeNode* root) {
    ans_ = INT_MIN;
    walk(root);
    return ans_;
  }

 private:
  int ans_;

  int walk(TreeNode* node) {
    if (node == nullptr) return 0;

    int pl = max(0, walk(node->left));
    int pr = max(0, walk(node->right));

    ans_ = max(ans_, node->val + pl + pr);

    return max(node->val + pl, node->val + pr);
  }
};
// @lc code=end

