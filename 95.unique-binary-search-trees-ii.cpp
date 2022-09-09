/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
  vector<TreeNode*> generateTrees(int n) { return genTrees(1, n); }

 private:
  vector<TreeNode*> genTrees(int l, int r) {
    vector<TreeNode*> trees;

    if (l > r) return {nullptr};

    for (int i = l; i <= r; ++i) {
      const auto& lefts = genTrees(l, i - 1);
      const auto& rights = genTrees(i + 1, r);

      for (auto left : lefts)
        for (auto right : rights) {
          trees.push_back(new TreeNode(i, left, right));
        }
    }

    return trees;
  }
};
// @lc code=end

