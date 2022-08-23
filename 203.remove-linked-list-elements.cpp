/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur) {
            if(cur->val == val) {
                prev->next = cur->next;

                // ListNode* tmp = cur;
                cur = cur->next;
                // delete tmp;
                continue;
            }

            prev = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
// @lc code=end

