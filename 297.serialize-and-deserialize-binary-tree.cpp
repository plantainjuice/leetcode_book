/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
#include <queue>

class Codec {
public:

    // Encodes a tree to a single string.
 string serialize(TreeNode* root) {
   if (root == nullptr) return "";

   queue<TreeNode*> q;
   q.push(root);

   stringstream ss;

   while (!q.empty()) {
     TreeNode* node = q.front();
     q.pop();

     if (node == nullptr)
       ss << "#,";
     else
       ss << to_string(node->val) << ",";

     if (node != nullptr) {
       q.push(node->left);
       q.push(node->right);
     }
   }

   return ss.str();
 }

 // Decodes your encoded data to tree.
 TreeNode* deserialize(string data) {
   if (data.size() == 0) return nullptr;

    stringstream ss(data);
    string s;

    getline(ss, s, ',');
    TreeNode* root = new TreeNode(stoi(s));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        getline(ss, s, ',');
        if (s == "#")
          node->left = nullptr;
        else {
          node->left = new TreeNode(stoi(s));
          q.push(node->left);
        }

        getline(ss, s, ',');
        if (s == "#")
          node->right = nullptr;
        else {
          node->right = new TreeNode(stoi(s));
          q.push(node->right);
        }
    }

    return root;
 }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

