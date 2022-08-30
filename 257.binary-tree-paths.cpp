/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <vector>

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        function<void(TreeNode*, string)> walk;
        walk = [&](TreeNode* node, string s) {
          if (!node) return;

          bool is_leaf = !node->left && !node->right;

          if (s == "") {
            s += to_string(node->val);
          } else {
            s += "->" + to_string(node->val);
          }

          if (is_leaf) ans.push_back(s);

          if (node->left) walk(node->left, s);
          if (node->right) walk(node->right, s);
        };

        walk(root, "");

        return ans;
    }
};
// @lc code=end

