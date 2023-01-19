/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    int max_diff = 0;

    function<void(TreeNode*, pair<int, int>)> travel = [&](TreeNode* node, pair<int, int> minmax) -> void {
      if (node == nullptr) return;

      max_diff = max(max_diff, abs(minmax.first - node->val));
      max_diff = max(max_diff, abs(minmax.second - node->val));

      minmax = {min(minmax.first, node->val), max(minmax.second, node->val)};

      travel(node->left, minmax);
      travel(node->right, minmax);
    };

    travel(root, {root->val, root->val});

    return max_diff;
  }
};
// @lc code=end
