/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  int getMinimumDifference(TreeNode* root) {
    midTraversal(root);
    return min_diff;
  }

 private:
  int min_diff = INT_MAX;

  pair<int, int> midTraversal(TreeNode* root) {
    int l = root->val;
    int r = root->val;

    if (root->left != nullptr) {
      pair<int, int> lr = midTraversal(root->left);
      min_diff = min(min_diff, abs(root->val - lr.second));
      l = lr.first;
    }

    if (root->right != nullptr) {
      pair<int, int> lr = midTraversal(root->right);
      min_diff = min(min_diff, abs(root->val - lr.first));
      r = lr.second;
    }

    return {l, r};
  }
};
// @lc code=end

