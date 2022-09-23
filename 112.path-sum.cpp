/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
 bool hasPathSum(TreeNode* root, int targetSum) {
   if (root == nullptr) return false;

   // is leaf
   if (root->left == nullptr && root->right == nullptr) {
     if (targetSum == root->val) return true;
     return false;
   }

   bool l = hasPathSum(root->left, targetSum - root->val);

   // prune
   if(l) return l;

   bool r = hasPathSum(root->right, targetSum - root->val);

   return r;
 }
};
// @lc code=end

