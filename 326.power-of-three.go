/*
 * @lc app=leetcode id=326 lang=golang
 *
 * [326] Power of Three
 */

// @lc code=start
func isPowerOfThree(n int) bool {
	for n >= 3 {
		if n%3 == 0 {
			n = n / 3
		} else {
			return false
		}
	}

	return n == 1
}

// @lc code=end
