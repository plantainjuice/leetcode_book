/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
  int sumRootToLeaf(TreeNode* root) {
    int sum = 0;
    travel(root, 0, sum);

    return sum;
  }

 private:
  void travel(TreeNode* node, int last, int& sum) {
    if (node == nullptr) return;

    // leaf node
    int cur = (last << 1) + node->val;

    if (node->left == nullptr && node->right == nullptr) {
      sum += cur;
    }

    travel(node->left, cur, sum);
    travel(node->right, cur, sum);
  }
};
// @lc code=end

