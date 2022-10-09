/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inOrder(root, nums);  // inorder iterate get sorted list

    int i = 0, j = nums.size() - 1;

    while (i < j) {
      int sum = nums[i] + nums[j];
      if (sum == k)
        return true;
      else if (sum < k)
        ++i;
      else
        --j;
    }

    return false;
  }

 private:
  void inOrder(TreeNode* node, vector<int>& nums) {
    if (node == nullptr) return;

    inOrder(node->left, nums);
    nums.push_back(node->val);
    inOrder(node->right, nums);
  }
};
// @lc code=end

