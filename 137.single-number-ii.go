/*
 * @lc app=leetcode id=137 lang=golang
 *
 * [137] Single Number II
 */

// @lc code=start
func singleNumber(nums []int) int {
	ones, twos := 0, 0
	for _, n := range nums {
		ones = (ones ^ n) & ^twos
		twos = (twos ^ n) & ^ones
	}

	return ones
}
// @lc code=end

