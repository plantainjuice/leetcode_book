/*
 * @lc app=leetcode id=147 lang=rust
 *
 * [147] Insertion Sort List
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
    pub fn insertion_sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }
        let mut head = head.unwrap();
        let mut current = head.next.take();
        let mut result = ListNode::new(-1);
        result.next = Some(Box::new(ListNode::new(head.val)));
        let mut result = Some(Box::new(result));
        while current.is_some() {
            let mut pre = result.as_mut().unwrap(); //持有一个链表节点的可变引用
            let cu_v = current.as_ref().unwrap().val;
            while pre.next.is_some() {
                if pre.next.as_ref().unwrap().val >= cu_v {
                    //找到应该插入在哪一个节点之后
                    break;
                }
                pre = pre.next.as_mut().unwrap(); //将当前可变引用指向下一个节点
            }
            let temp = pre.next.take();
            let mut data = ListNode::new(cu_v);
            data.next = temp;
            pre.next = Some(Box::new(data));
            current = current.unwrap().next.take();
        }
        return result.unwrap().next;
    }
}
// @lc code=end
