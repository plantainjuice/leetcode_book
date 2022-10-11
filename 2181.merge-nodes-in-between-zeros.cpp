/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
      if (cur->next->val == 0) {
        // check if last 0
        if(cur->next->next == nullptr) {
            cur->next = nullptr;
            break;
        }

        cur = cur->next;
      } else {
        cur->val += cur->next->val;
        cur->next = cur->next->next;
      }
    }

    return head;
  }
};
// @lc code=end

