/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;

    auto dummy = head->next;
    auto last = head;

    while (head) {
      if (head->next == nullptr) break;
      auto next = head->next;

      auto tmp = next->next;

      last->next = next;
      next->next = head;
      head->next = tmp;

      last = head;
      head = head->next;
    }

    return dummy;
  }
};
// @lc code=end

