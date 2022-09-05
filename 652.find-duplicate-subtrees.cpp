/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
  // https://zxi.mytechroad.com/blog/tree/leetcode-652-find-duplicate-subtrees/
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    map<long, pair<int, int>> counts; // tree_key, <tree_id, count>

    getTreeId(root, counts, ans);

    return ans;
  }

  int getTreeId(TreeNode* node, map<long, pair<int, int>>& counts,
                vector<TreeNode*>& ans) {
    if (node == nullptr) return 0;

    long tree_key =
        (static_cast<long>(static_cast<unsigned>(node->val)) << 32) +
        (getTreeId(node->left, counts, ans) << 16) +
        getTreeId(node->right, counts, ans);

    auto& p = counts[tree_key];
    if (p.second++ == 0)
      p.first = counts.size();
    else if (p.second == 2)
      ans.push_back(node);

    return p.first;
  }
};
// @lc code=end

