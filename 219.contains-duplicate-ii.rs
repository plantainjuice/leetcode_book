/*
 * @lc app=leetcode id=219 lang=rust
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
use std::{collections::HashMap, usize};

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
      let mut m: HashMap<i32, usize> = HashMap::new();

      for (i, v) in nums.iter().enumerate(){
        match m.get(v) {
          Some(j) => {
            if i - *j <= k as usize{
              return true;
            }
            m.insert(*v, i);
          }
          None => {
            m.insert(*v, i);
          }
        }

      }

      false
    }
}
// @lc code=end
