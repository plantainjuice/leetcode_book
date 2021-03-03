/*
 * @lc app=leetcode id=75 lang=golang
 *
 * [75] Sort Colors
 */

// @lc code=start
func sortColors(nums []int) {
	if len(nums) == 0 {
		return
	}

	r, w, b := 0, 0, 0

	for _, num := range nums {
		if num == 0 {
			nums[b] = 2
			b++
			nums[w] = 1
			w++
			nums[r] = 0
			r++
		} else if num == 1 {
			nums[b] = 2
			b++
			nums[w] = 1
			w++
		} else if num == 2 {
			b++
		}
	}
}

// @lc code=end
