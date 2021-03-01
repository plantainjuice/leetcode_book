/*
 * @lc app=leetcode id=171 lang=golang
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
func titleToNumber(s string) int {
	res := 0
	for _, c := range s {
		res *= 26
		res += int(c - 'A' + 1)
	}
    
	return res
}
// @lc code=end

