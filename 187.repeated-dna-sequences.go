/*
 * @lc app=leetcode id=187 lang=golang
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
func findRepeatedDnaSequences(s string) []string {
	if len(s) < 10 {
		return []string{}
	}
	res, cache := []string{}, make(map[string]int)

	for i := 0; i <= len(s)-10; i++ {
		cur := s[i : i+10]

		if cache[cur] == 1 {
			res = append(res, cur)
		}
		cache[cur]++
	}

	return res
}

// @lc code=end
