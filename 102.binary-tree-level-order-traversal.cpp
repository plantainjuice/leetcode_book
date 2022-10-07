/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> layer;
      int n = q.size();

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);

        layer.push_back(node->val);
      }

      ans.push_back(move(layer));
    }

    return ans;
  }
};
// @lc code=end

