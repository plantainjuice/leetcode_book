/*
 * @lc app=leetcode id=230 lang=rust
 *
 * [230] Kth Smallest Element in a BST
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
impl Solution {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut is_bottom_left = false;
        let mut cnt = 0;
        let mut result = 0;
        Self::internal(root, &mut |r| -> bool {
            if !is_bottom_left && r.borrow().left.is_none() {
                is_bottom_left = true;
            }
            if is_bottom_left {
                cnt += 1;
            }
            if cnt == k {
                result = r.borrow().val;
            }
            return cnt == k;
        });
        result
    }

    fn internal(
        root: Option<Rc<RefCell<TreeNode>>>,
        f: &mut impl FnMut(Rc<RefCell<TreeNode>>) -> bool,
    ) -> bool {
        if root.is_none() {
            return false;
        }
        let r = root.unwrap();
        if Self::internal(r.borrow().left.clone(), f) {
            return true;
        }
        if f(r.clone()) {
            return true;
        }
        return Self::internal(r.borrow().right.clone(), f);
    }
}
// @lc code=end
