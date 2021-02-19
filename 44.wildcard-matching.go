/*
 * @lc app=leetcode id=44 lang=golang
 *
 * [44] Wildcard Matching
 */

// @lc code=start
func isMatch(s string, p string) bool {
	// var dp [len(s) + 1][len(p) + 1]bool
	var dp [][]bool
	for i := 0; i < len(s)+1; i++ {
		var row []bool
		for j := 0; j < len(p)+1; j++ {
			row = append(row, false)
		}
		dp = append(dp, row)
	}
	dp[0][0] = true

	for i := 1; i <= len(p); i++ {
		if p[i-1] == '*' {
			dp[0][i] = dp[0][i-1]
		}
	}

	for i := 1; i < len(s)+1; i++ {
		for j := 1; j < len(p)+1; j++ {
			if p[j-1] == '?' {
				dp[i][j] = dp[i-1][j-1]
			} else if p[j-1] == '*' {
				dp[i][j] = dp[i-1][j] || dp[i][j-1]
			} else {
				dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
			}
		}
	}

	return dp[len(s)][len(p)]
}
// @lc code=end
