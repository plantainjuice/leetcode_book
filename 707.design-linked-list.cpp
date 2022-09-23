/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */


// @lc code=start
class MyLinkedList {
private:
 struct ListNode {
   int val;
   ListNode* next;
   ListNode(int v) : val(v), next(nullptr) {}
 };

 ListNode* head_;

public:
 MyLinkedList() { head_ = nullptr; }

 int get(int index) {
   ListNode* cur = head_;
   while (index--) {
     if (cur == nullptr) return -1;
     cur = cur->next;
   }

   if (cur == nullptr) return -1;

   return cur->val;
 }

 void addAtHead(int val) {
    ListNode* node = new ListNode(val);
    node->next = head_;
    head_ = node;
 }

 void addAtTail(int val) {
   if (head_ == nullptr) {
     head_ = new ListNode(val);
     return;
   }

   ListNode* cur = head_;
   while (cur->next) {
     cur = cur->next;
   }

   cur->next = new ListNode(val);
 }

 void addAtIndex(int index, int val) {
   if (index == 0) return addAtHead(val);

   // get the previous one
   index -= 1;

   ListNode* cur = head_;
   while (index--) {
     if (cur == nullptr) return;
     cur = cur->next;
   }

   if (cur == nullptr) return;

   ListNode* node = new ListNode(val);
   ListNode* tmp = cur->next;

   cur->next = node;
   node->next = tmp;
 }

 void deleteAtIndex(int index) {
   if (index == 0) {
     if (head_ != nullptr) head_ = head_->next;
     return;
   };

   // get the previous one
   index -= 1;

   ListNode* cur = head_;
   while (index--) {
     if (cur == nullptr) return;
     cur = cur->next;
   }

   if (cur != nullptr && cur->next != nullptr) {
     cur->next = cur->next->next;
   }
 }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

