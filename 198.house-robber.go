/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */

// @lc code=start
func rob(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	} else if length == 1 {
		return nums[0]
	} else if length == 2 {
		return max(nums[0], nums[1])
	}

	dp := make([]int, length)

	dp[0] = nums[0]
	dp[1] = nums[1]
	dp[2] = nums[0] + nums[2]

	for i := 3; i < length; i++ {
		dp[i] = max(dp[i-2], dp[i-3]) + nums[i]
	}

	return max(dp[length-1], dp[length-2])
}

func max(a, b int) int {
	if a < b {
		return b
	}

	return a
}

// @lc code=end

