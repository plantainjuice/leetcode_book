/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            ++len;
            cur = cur->next;
        }
        
        int mid_len = (len+1) / 2;
        ListNode* mid = head;
        while(--mid_len) {
            mid = mid->next;
        }
        
        ListNode* last = mid, *pre = nullptr;
        while(last) {
            ListNode* next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
// @lc code=end

