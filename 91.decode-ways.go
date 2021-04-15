/*
 * @lc app=leetcode id=91 lang=golang
 *
 * [91] Decode Ways
 */

// @lc code=start
func numDecodings(s string) int {
	if len(s) == 0 {
		return 0
	}

	dp := make([]int, len(s)+1)
	dp[0] = 1
	if s[:1] == "0" {
		dp[1] = 0
	} else {
		dp[1] = 1
	}

	for i := 2; i <= len(s); i++ {
		lastNum, _ := strconv.Atoi(s[i-1 : i])
		if 1 <= lastNum && lastNum <= 9 {
			dp[i] += dp[i-1]
		}

		lastNum, _ = strconv.Atoi(s[i-2 : i])
		if 10 <= lastNum && lastNum <= 26 {
			dp[i] += dp[i-2]
		}
	}

	return dp[len(s)]
}

// @lc code=end
