/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        auto head = root;
        while (root){
            auto dummy = new Node(0);
            auto tail = dummy;

            while(root){
                if (root->left){
                    tail->next = root->left;
                    tail = tail->next;
                }

                if (root->right){
                    tail->next = root->right;
                    tail = tail->next;
                }

                root = root->next;
            }
            root = dummy->next;
        }

        return head;
    }
};
// @lc code=end
