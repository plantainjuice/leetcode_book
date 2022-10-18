/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    postTravel(root);

    vector<int> ans;
    for (auto& kv : sum_cnt_) {
      if (kv.second == max_cnt_) ans.push_back(kv.first);
    }

    return ans;
  }

 private:
  map<int, int> sum_cnt_;
  int max_cnt_;

  int postTravel(TreeNode* node) {
    if (node == nullptr) return INT_MIN;

    int l = postTravel(node->left);
    int r = postTravel(node->right);

    int sum = node->val;
    if (l != INT_MIN) sum += l;
    if (r != INT_MIN) sum += r;

    ++sum_cnt_[sum];
    max_cnt_ = max(max_cnt_, sum_cnt_[sum]);

    return sum;
  }
};
// @lc code=end

