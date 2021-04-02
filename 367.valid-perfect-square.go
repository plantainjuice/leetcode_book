/*
 * @lc app=leetcode id=367 lang=golang
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
func isPerfectSquare(num int) bool {
	low, high := 1, num

	for low <= high {
		mid := low + (high-low)/2
		sqr := mid * mid
		if sqr == num {
			return true
		}

		if sqr > num {
			high = mid - 1
		} else {
			low = mid + 1
		}

	}
	return false
}

// @lc code=end
