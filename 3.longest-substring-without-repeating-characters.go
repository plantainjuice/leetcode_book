/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	result, left, right, freq := 0, 0, 0, make([]int, 256)

	for left < len(s) {
		if right < len(s) && freq[s[right]-'a'] == 0 {
			freq[s[right]-'a']++
			right++
		} else {
			freq[s[left]-'a']--
			left++
		}
		result = max(result, right-left)
	}
	return result
}

func max(a, b int)int{
	if a < b {
		return b
	}
	return a
}

// @lc code=end