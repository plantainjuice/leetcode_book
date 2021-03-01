/*
 * @lc app=leetcode id=168 lang=golang
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
func convertToTitle(n int) string {
	res := []byte{}
	for n > 0 {
		res = append([]byte{'A' + byte((n-1)%26)}, res...)
		n = (n - 1) / 26
	}

	return string(res)
}

// @lc code=end

