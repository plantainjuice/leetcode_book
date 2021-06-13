/*
 * @lc app=leetcode id=206 lang=rust
 *
 * [206] Reverse Linked List
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }

        let mut node_p1 = None;
        let mut node_p2 = &head;

        while let Some(node) = node_p2{
            node_p1 = Some(Box::new(ListNode {
                next: node_p1,
                val: node.val
            }));

            node_p2 = &node.next;
        }

        return node_p1
    }
}
// @lc code=end
