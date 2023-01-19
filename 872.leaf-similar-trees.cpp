/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    function<void(TreeNode*, vector<int>&)> mid_traverse =
        [&](TreeNode* node, vector<int>& v) -> void {
      if (node == nullptr) return;

      // leaf node
      if (node->left == nullptr && node->right == nullptr) {
        v.push_back(node->val);
        return;
      }

      mid_traverse(node->left, v);
      mid_traverse(node->right, v);
    };

    vector<int> v1;
    vector<int> v2;
    mid_traverse(root1, v1);
    mid_traverse(root2, v2);

    return v1 == v2;
  }
};
// @lc code=end
