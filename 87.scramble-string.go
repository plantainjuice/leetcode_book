/*
 * @lc app=leetcode id=87 lang=golang
 *
 * [87] Scramble String
 */

// @lc code=start
func isScramble(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	if s1 == s2 {
		return true
	}
	lg := len(s1)
	dp := make([][][]bool, lg)
	for i := 0; i < lg; i++ {
		dp[i] = make([][]bool, lg)
		for j := 0; j < lg; j++ {
			dp[i][j] = make([]bool, lg+1)
			dp[i][j][1] = s1[i] == s2[j]
		}
	}

	for l := 2; l <= lg; l++ {
		for i := 0; i <= lg-l; i++ {
			for j := 0; j <= lg-l; j++ {
				for k := 1; k < l; k++ {
					if (dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k]) {
						dp[i][j][l] = true
						break
					}
				}
			}

		}
	}
	return dp[0][0][lg]
}

// @lc code=end
