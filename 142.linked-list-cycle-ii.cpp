/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
    }

    // no cycle
    if (fast == nullptr || fast->next == nullptr) return nullptr;

    ListNode* find = head;
    while (find != slow) {
      find = find->next;
      slow = slow->next;
    }

    return find;
  }
};
// @lc code=end

