/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> res;
    for (auto* p = head; p != nullptr; p = p->next) res.push_back(p->val);

    vector<int> ans(res.size());
    stack<pair<int, int>> st;  // <value, index>
    int i = 0;
    while (head) {
      while (!st.empty() && head->val > st.top().first) {
        ans[st.top().second] = head->val;
        st.pop();
      }

      st.push({head->val, i});

      head = head->next;
      ++i;
    }

    ans[res.size() - 1] = 0;

    return ans;
  }
};
// @lc code=end

