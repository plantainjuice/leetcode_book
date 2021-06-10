/*
 * @lc app=leetcode id=205 lang=rust
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let l1 = s.len();
        let l2 = t.len();
        if l1 != l2 {
            return false;
        }

        let mut m1: HashMap<char, usize> = HashMap::new();
        let mut m2: HashMap<char, usize> = HashMap::new();

        let s = &mut s.chars();
        let t = &mut t.chars();

        for i in 0..l1 {
            let ch1 = s.next().unwrap();
            let ch2 = t.next().unwrap();

            if !m1.insert(ch1, i).eq(&m2.insert(ch2, i)){
              return false;
            }
        }

        true
    }
}
// @lc code=end
