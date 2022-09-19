/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;

    function<void(TreeNode*, bool)> f;
    f = [&](TreeNode* node, bool is_left) {
      if (node == nullptr) return;

      // is left-leave
      if (is_left && node->left == nullptr && node->right == nullptr) {
        sum += node->val;
        return;
      }

      f(node->left, true);
      f(node->right, false);
    };

    f(root, false);

    return sum;
  }
};
// @lc code=end

