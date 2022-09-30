/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root == nullptr) return {};

    vector<vector<int>> ans;

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
      int n = q.size();

      vector<int> vec;

      while (n--) {
        TreeNode* node = q.front();
        q.pop();

        vec.push_back(node->val);

        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }

      ans.push_back(move(vec));
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

