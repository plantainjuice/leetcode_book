/*
 * @lc app=leetcode id=453 lang=golang
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
func minMoves(nums []int) int {
	sum, min, l := 0, nums[0], len(nums)

	for _, n := range nums {
		sum += n

		if min > n {
			min = n
		}
	}

	return sum - min*l
}

// @lc code=end
