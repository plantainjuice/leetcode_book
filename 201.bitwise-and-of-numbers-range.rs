/*
 * @lc app=leetcode id=201 lang=rust
 *
 * [201] Bitwise AND of Numbers Range
 */

q// @lc code=start
impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let mut cnt = 0;
        let mut left = left;
        let mut right = right;

        while left != right{
            left = left >> 1;
            right = right >> 1;
            cnt += 1;
        }

        return left << cnt;
    }
}
// @lc code=end
