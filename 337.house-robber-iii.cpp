/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
  int rob(TreeNode* root) {
    auto r = rob_(root);
    return max(r.first, r.second);
  }

 private:
  // <first> rob cur
  // <second> not rob cur
  pair<int, int> rob_(TreeNode* node) {
    if (node == nullptr) return {0, 0};

    auto l = rob_(node->left);
    auto r = rob_(node->right);

    int val1 = node->val + l.second + r.second;
    int val2 = max(l.first, l.second) + max(r.first, r.second);

    return {val1, val2};
  }
};
// @lc code=end

