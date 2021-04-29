/*
 * @lc app=leetcode id=22 lang=golang
 *
 * [22] Generate Parentheses
 */

// @lc code=start
func generateParenthesis(n int) []string {
	res := []string{}
	if n == 0 {
		return res
	}

	findParenthesis(n, n, "", &res)

	return res
}

func findParenthesis(lindex, rindex int, cur string, res *[]string) {
	if lindex == 0 && rindex == 0 {
		*res = append(*res, cur)
		return
	}

	if lindex > 0 {
		findParenthesis(lindex-1, rindex, cur+"(", res)
	}

	if rindex > 0 && rindex > lindex {
		findParenthesis(lindex, rindex-1, cur+")", res)
	}
}

// @lc code=end
