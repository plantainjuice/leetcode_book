/*
 * @lc app=leetcode id=1124 lang=golang
 *
 * [1124] Longest Well-Performing Interval
 */

// @lc code=start
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestWPI(hours []int) (wpi int) {
	for i, v := range hours {
		if v > 8 {
			hours[i] = 1
		} else {
			hours[i] = -1
		}
	}

	hash := make(map[int]int)
	curr := 0
	for i, v := range hours {
		curr += v
		hash[curr] = i
	}
	for k, v := range hash {
		if k > 0 {
			wpi = max(wpi, v+1)
		}
	}

	magic := 1
	for i, v := range hours {
		magic += v
		wpi = max(wpi, hash[magic]-i)
	}
	return wpi
}

// @lc code=end

