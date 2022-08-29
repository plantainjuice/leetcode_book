/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode* mid = reverse(slow);

    while (mid != nullptr && head != nullptr) {
      if (mid->val != head->val) return false;
      mid = mid->next;
      head = head->next;
    }

    return true;
  }

 private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
  }
};
// @lc code=end

