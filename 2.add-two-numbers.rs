/*
 * @lc app=leetcode id=2 lang=rust
 *
 * [2] Add Two Numbers
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
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut result = None;
        let mut temp = &mut result;
        let mut t = (l1, l2, 0, 0); // l1, l2, val, carry
        loop {
            t = match t {
                (None, None, _, 0) => break,
                (None, None, _, carry) => (None, None, carry, 0),
                (None, Some(list), _, carry) | (Some(list), None, _, carry) => (
                    list.next,
                    None,
                    (list.val + carry) % 10,
                    (list.val + carry) / 10,
                ),
                (Some(l1), Some(l2), _, carry) => (
                    l1.next,
                    l2.next,
                    (l1.val + l2.val + carry) % 10,
                    (l1.val + l2.val + carry) / 10,
                ),
            };
            *temp = Some(Box::new(ListNode::new(t.2)));
            temp = &mut temp.as_mut().unwrap().next;
        }
        result
    }
}
// @lc code=end
