/*
 * @lc app=leetcode id=62 lang=golang
 *
 * [62] Unique Paths
 */

// @lc code=start
func uniquePaths(m int, n int) int {
	if m == 0 || n == 0 {
		return 0
	}

	if m == 1 || n == 1 {
		return 1
	}

	return C(m+n-2, n-1)
}

func C(a, b int) int {
	res, b := 1, min(a-b, b)
	for i := 1; i <= b; i++ {
		res *= (a - i + 1)
		res /= i
	}

	return res
}


func min(a, b int)int{
    if a < b {
        return a
    }

    return b
}
// @lc code=end
