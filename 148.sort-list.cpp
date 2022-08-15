/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    return mergeList(left, right);
  }

  ListNode* mergeList(ListNode* left, ListNode* right) {
    ListNode dummyHead;
    ListNode* ptr = &dummyHead;
    while (left && right) {
      if (left->val <= right->val) {
        ptr->next = left;
        left = left->next;
      } else {
        ptr->next = right;
        right = right->next;
      }

      ptr = ptr->next;
    }

    if (left)
      ptr->next = left;
    else
      ptr->next = right;

    return dummyHead.next;
  }

  ListNode* getMid(ListNode* head) {
    // ListNode* midPrev = head;
    ListNode* midPrev = nullptr;
    while (head && head->next) {
      midPrev = (midPrev == nullptr) ? head : midPrev->next;
      head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;

    return mid;
  }
};
// @lc code=end
