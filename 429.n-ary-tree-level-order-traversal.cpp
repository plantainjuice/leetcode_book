/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if(root == nullptr) return {};

    vector<vector<int>> ans;

    queue<Node*> q;
    queue<Node*> q2;
    q.push(root);

    while (!q.empty() || !q2.empty()) {
      if (q.empty()) {
        swap(q, q2);
        continue;
      }

      vector<int> tmp;
      while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        tmp.push_back(node->val);

        for (Node* c : node->children) {
          if (c != nullptr) q2.push(c);
        }
      }

      if (tmp.size()) ans.push_back(move(tmp));
    }

    return ans;
  }
};
// @lc code=end

