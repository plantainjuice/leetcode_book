/*
 * @lc app=leetcode id=71 lang=golang
 *
 * [71] Simplify Path
 */

// @lc code=start
func simplifyPath(path string) string {
	stack, arr := []string{}, strings.Split(path, "/")

	for _, dir := range arr {
		if dir == ".." {
			if len(stack) > 0 {
				stack = stack[0 : len(stack)-1]
			}
		} else if dir != "." && len(dir) > 0 {
			stack = append(stack, dir)
		}
	}

	return "/" + strings.Join(stack, "/")
}
// @lc code=end
