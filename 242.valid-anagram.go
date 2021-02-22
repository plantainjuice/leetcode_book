/*
 * @lc app=leetcode id=242 lang=golang
 *
 * [242] Valid Anagram
 */

// @lc code=start
func isAnagram(s string, t string) bool {
	alphabet := make([]int, 26)
	sBytes := []byte(s)
	tBytes := []byte(t)

	if len(sBytes) != len(tBytes) {
		return false
	}

	for _, i := range sBytes {
		alphabet[i - 'a']++
	}

	for _, i := range tBytes {
		alphabet[i - 'a']--
	}

	for _, i := range alphabet {
		if i != 0{
			return false
		}
	}

	return true
}
// @lc code=end

