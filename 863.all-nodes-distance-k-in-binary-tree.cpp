/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;

    function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int cur) -> int {
      if (node == nullptr) return INT_MIN;

      // meet the distance
      if (cur == k) {
        ans.push_back(node->val);
        return INT_MIN;
      }

      // find the target
      if (node == target) {
        if(k == 0) {
            ans.push_back(node->val);
            return INT_MIN;
        }

        dfs(node->left, 1);
        dfs(node->right, 1);
        return 1;
      }

      // check left child
      int l = dfs(node->left, cur + 1);
      if (l > 0) {
        if (l == k) {
          ans.push_back(node->val);
          return INT_MIN;
        }

        dfs(node->right, l + 1);
        return l + 1;
      }

      // check right child
      int r = dfs(node->right, cur + 1);
      if (r > 0) {
        if (r == k) {
          ans.push_back(node->val);
          return INT_MIN;
        }

        dfs(node->left, r + 1);
        return r + 1;
      }

      return INT_MIN;
    };

    dfs(root, INT_MIN);

    return ans;
  }
};
// @lc code=end

