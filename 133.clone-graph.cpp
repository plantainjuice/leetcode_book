/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node* cloneGraph(Node* root) {
    if(root == nullptr) return nullptr;

    queue<Node*> Q;
    unordered_set<Node*> S;         // done
    unordered_map<Node*, Node*> M;  // <old, new>

    Q.push(root);

    while (!Q.empty()) {
      Node* node = Q.front();
      Q.pop();

      if (S.count(node)) continue;

      Node* new_node = nullptr;
      if(!M.count(node))
        new_node = new Node(node->val);
      else 
        new_node = M[node];

      for (auto n : node->neighbors) {
        if (!M.count(n)) M[n] = new Node(n->val);
        Q.push(n);
        new_node->neighbors.push_back(M[n]);
      }

      S.insert(node);
      M[node] = new_node;
    }

    return M[root];
  }
};
// @lc code=end

