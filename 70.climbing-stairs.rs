/*
 * @lc app=leetcode id=70 lang=rust
 *
 * [70] Climbing Stairs
 */

// @lc code=start
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1 {
            return 1;
        } else if n == 2 {
            return 2;
        }
        let mut n1 = 1;
        let mut n2 = 2;
        let mut i = 2;
        while i < n {
            let t = n1 + n2;
            n1 = n2;
            n2 = t;
            i += 1;
        }
        n2
    }
}
// @lc code=end
