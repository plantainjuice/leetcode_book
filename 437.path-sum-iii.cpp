/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

// O(n)
class Solution {
 public:
  int pathSum(TreeNode* root, int targetSum) {
    map<long, int> prefix;
    prefix[0]++;

    backtrack(targetSum, prefix, 0, root);

    return ans;
  }

 private:
  int ans = 0;
  void backtrack(const int targetSum, map<long, int>& prefix, long sum, TreeNode* root) {
    if (root == nullptr) return;

    sum += root->val;
    if (prefix.find(sum - targetSum) != prefix.end()) {
      ans += prefix[sum - targetSum];
    }

    ++prefix[sum];
    backtrack(targetSum, prefix, sum, root->left);
    backtrack(targetSum, prefix, sum, root->right);
    --prefix[sum];
  }
};

// O(n*n)
// class Solution {
//  public:
//   int pathSum(TreeNode* root, int targetSum) {
//     if (root == nullptr) return 0;

//     backtrack(targetSum, 0, root);

//     pathSum(root->left, targetSum);
//     pathSum(root->right, targetSum);

//     return ans;
//   }

//  private:
//   int ans = 0;
//   void backtrack(const int targetSum, long sum, TreeNode* root) {
//     if (root == nullptr) return;

//     if ((sum + root->val) == targetSum) {
//       ans += 1;
//     }

//     // include root
//     backtrack(targetSum, sum + root->val, root->left);
//     backtrack(targetSum, sum + root->val, root->right);
//   }
// };
// @lc code=end

