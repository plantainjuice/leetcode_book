/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    backtrack(root, targetSum, 0, path);
    return ans;
  }

 private:
  vector<vector<int>> ans;

  void backtrack(TreeNode* node, const int targetSum, int curSum, vector<int>& path) {
    if (node == nullptr) return;

    // is leaf node
    if (node->left == nullptr && node->right == nullptr) {
      if ((curSum + node->val) == targetSum) {
        path.push_back(node->val);
        ans.push_back(path);
        path.pop_back();
      }
      return;
    }

    path.push_back(node->val);
    backtrack(node->left, targetSum, curSum + node->val, path);
    path.pop_back();

    path.push_back(node->val);
    backtrack(node->right, targetSum, curSum + node->val, path);
    path.pop_back();
  }
};
// @lc code=end

