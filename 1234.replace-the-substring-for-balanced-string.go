/*
 * @lc app=leetcode id=1234 lang=golang
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func balancedString(s string) int {
	n := len(s)

	cnt := make(map[byte]int)
	for i := 0; i < n; i++ {
		cnt[s[i]] += 1
	}

	ans := math.MaxInt32
	l, h := 0, 0

	for l < n && h <= n {
		if cnt['Q'] <= n/4 && cnt['W'] <= n/4 && cnt['E'] <= n/4 && cnt['R'] <= n/4 {
			ans = min(ans, h-l)
			cnt[s[l]] += 1
			l++
		} else {
			if h < n {
				cnt[s[h]] -= 1
			}
			h++
		}
	}

	return ans
}

// @lc code=end

