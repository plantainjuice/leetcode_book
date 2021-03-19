/*
 * @lc app=leetcode id=274 lang=golang
 *
 * [274] H-Index
 */

// @lc code=start
func hIndex(citations []int) int {
	n, cite_count := len(citations), make([]int, len(citations)+1)

	for _, c := range citations {
		if c >= n {
			cite_count[n]++
		} else {
			cite_count[c]++
		}
	}

	count := 0
	for i := n; i >= 0; i-- {
		count += cite_count[i]
		if count >= i {
			return i
		}
	}

	return 0
}
// @lc code=end

