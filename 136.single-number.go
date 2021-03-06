/*
 * @lc app=leetcode id=136 lang=golang
 *
 * [136] Single Number
 */

// @lc code=start
func singleNumber(nums []int) int {
	res := 0
	for _, n := range nums {
		res ^= n
	}

	return res
}
// @lc code=end

