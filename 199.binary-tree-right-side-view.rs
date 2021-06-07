/*
 * @lc app=leetcode id=199 lang=rust
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if root.is_none(){
            return vec![];
        }

        let mut res: Vec<i32> = vec![];
        let mut q: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
        q.push_back(root);

        while q.len() > 0{
            let l = q.len();
            let last_node = &q.back().unwrap();
            res.push(last_node.as_ref().unwrap().borrow().val);

            for _i in 0..l{
                let front = q.pop_front().unwrap();
                let mut next = front.as_ref().unwrap().borrow_mut();

                if next.left.is_some(){
                    q.push_back(next.left.take());
                }

                if next.right.is_some(){
                    q.push_back(next.right.take());
                }
            }
        }

        return res;
    }
}
// @lc code=end
