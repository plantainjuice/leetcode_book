/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto getLen = [] (ListNode * node) -> int {
            int len = 0;
            while(node != nullptr) {
                node = node->next;
                len++;
            }

            return len;
        };

        int lenA = getLen(headA);
        int lenB = getLen(headB);

        int diff = lenA - lenB;

        if (diff > 0) {
            while(diff--) headA = headA->next;
        } else {
            while(diff++) headB = headB->next;
        }

        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode * ha = headA;
    //     ListNode * hb = headB;

    //     while(ha != hb) {
    //         ha = ha == nullptr? headB : ha->next;
    //         hb = hb == nullptr? headA : hb->next;
    //     }

    //     return ha;
    // }
};
// @lc code=end

