/*
 * @lc app=leetcode id=268 lang=golang
 *
 * [268] Missing Number
 */

// @lc code=start
func missingNumber(nums []int) int {
	n, res := len(nums), 0

	for i := 0; i < n; i++ {
		res = res ^ i ^ nums[i]
	}

	return res ^ n
}

// @lc code=end
