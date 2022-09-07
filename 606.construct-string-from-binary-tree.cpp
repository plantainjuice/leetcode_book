/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode* root) {
      string ans;

      function<void(TreeNode * root)> pre_order;
      pre_order = [&](TreeNode* node) {
        if (node == nullptr) return;

        ans += "(";
        ans += to_string(node->val);

        pre_order(node->left);
        if (node->left == nullptr && node->right != nullptr) {
          ans += "()";
        }
        pre_order(node->right);

        ans += ")";
      };

      pre_order(root);

      return ans.substr(1, ans.size() - 2);
    }
};
// @lc code=end

