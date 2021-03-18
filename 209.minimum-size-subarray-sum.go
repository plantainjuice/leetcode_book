/*
 * @lc app=leetcode id=209 lang=golang
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
func minSubArrayLen(target int, nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	res, sum, i, j := len(nums)+1, nums[0], 0, 0

	for j < len(nums) {
		if sum < target && j < len(nums) {
			j++

			if j == len(nums){
				continue
			}

			sum += nums[j]
		} 

		if sum >= target {
			sum -= nums[i]
			res = min(res, j-i+1)
			i++
		}
	}

	if res == len(nums)+1 {
		return 0
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// @lc code=end

