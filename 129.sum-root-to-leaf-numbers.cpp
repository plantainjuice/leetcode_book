/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    dfs(root, 0, sum);
    return sum;
  }

 private:
  void dfs(TreeNode* node, int last, int& sum) {
    if (node == nullptr) return;

    int cur = last * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr) {
      sum += cur;
      return;
    }

    dfs(node->left, cur, sum);
    dfs(node->right, cur, sum);
  }
};
// @lc code=end

