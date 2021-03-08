/*
 * @lc app=leetcode id=300 lang=golang
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
func lengthOfLIS(nums []int) int {
	res, dp := 0, make([]int, len(nums)+1)
	dp[0] = 0

	for i := 1; i <= len(nums); i++ {
		for j := 1; j < i; j++ {
			if nums[i-1] > nums[j-1] {
				dp[i] = max(dp[i], dp[j])
			}
		}
		dp[i] += 1
		res = max(res, dp[i])
	}

	return res
}

func max(a, b int) int {
	if a < b {
		return b
	}

	return a
}
// @lc code=end
