/*
 * @lc app=leetcode id=191 lang=rust
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut res = 0i32;

        for _i in 0..32{
            res += ((n >> _i) & 0x1) as i32;
        }

        res
    }
}
// @lc code=end
