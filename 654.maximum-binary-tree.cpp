/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int max_val = nums[0];
    int max_val_index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > max_val) {
        max_val = nums[i];
        max_val_index = i;
      }
    }

    TreeNode* root = new TreeNode(max_val);

    if (max_val_index > 0) {
      vector<int> nums_l(nums.begin(), nums.begin() + max_val_index);
      root->left = constructMaximumBinaryTree(nums_l);
    }

    if (max_val_index < (nums.size() - 1)) {
      vector<int> nums_r(nums.begin() + max_val_index + 1, nums.end());
      root->right = constructMaximumBinaryTree(nums_r);
    }

    return root;
  }
};
// @lc code=end

