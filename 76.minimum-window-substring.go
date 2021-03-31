/*
 * @lc app=leetcode id=76 lang=golang
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
func minWindow(s string, t string) string {
	if s == "" || t == "" {
		return ""
	}

	var sFreq, tFreq [256]int
	result, left, right, minw, finalLeft, finalRight, count := "", 0, -1, len(s)+1, -1, -1, 0

	for i := 0; i < len(t); i++ {
		tFreq[t[i]-'a']++
	}

	for left < len(s) {
		if right+1 < len(s) && count < len(t) {
			char := s[right+1]
			sFreq[char-'a']++
			if sFreq[char-'a'] <= tFreq[char-'a'] {
				count++
			}
			right++
		} else {
			if right-left+1 < minw && count == len(t) {
				minw = right - left + 1
				finalLeft = left
				finalRight = right
			}

			char := s[left]
			if sFreq[char-'a'] == tFreq[char-'a'] {
				count--
			}
			sFreq[char-'a']--
			left++
		}
	}

	if minw != len(s)+1 {
		result = string(s[finalLeft : finalRight+1])
	}

	return result
}

// @lc code=end
