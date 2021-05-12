/*
 * @lc app=leetcode id=35 lang=rust
 *
 * [35] Search Insert Position
 */

// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut low, mut high) = (0, nums.len() - 1);

        while low <= high {
            let mid = low + (high - low) / 2;
            if nums[mid] == target{
                return mid as i32;
            } else if target < nums[mid]{
                if mid == 0{
                    return 0;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low as i32
    }
}
// @lc code=end
