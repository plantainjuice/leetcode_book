/*
 * @lc app=leetcode id=169 lang=golang
 *
 * [169] Majority Element
 */

// @lc code=start
func majorityElement(nums []int) int {
	res, count := nums[0], 0

	for _, num := range nums {
		if count == 0 {
			res, count = num, 1
		} else {
			if num == res {
				count++
			} else {
				count--
			}
		}
	}

	return res
}
// @lc code=end

