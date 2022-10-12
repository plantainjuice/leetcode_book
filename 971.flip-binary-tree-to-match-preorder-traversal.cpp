/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    int pos = 0;
    vector<int> ans;
    return travel(root, voyage, pos, ans) ? ans : vector<int> () = {-1};
  }

 private:
  bool travel(TreeNode* node, vector<int>& voyage, int& pos, vector<int>& ans) {
    if(node == nullptr) return true;

    if(node->val != voyage[pos++]) return false;

    auto l = node->left;
    auto r = node->right;

    if (l != nullptr && l->val != voyage[pos]) {
      ans.push_back(node->val);
      swap(l, r);
    }

    return travel(l, voyage, pos, ans) && travel(r, voyage, pos, ans);
  }
};
// @lc code=end

