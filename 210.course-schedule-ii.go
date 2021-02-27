/*
 * @lc app=leetcode id=210 lang=golang
 *
 * [210] Course Schedule II
 */

// @lc code=start
func findOrder(numCourses int, prerequisites [][]int) []int {
	in := make([]int, numCourses)
	frees := make([][]int, numCourses)
	next := make([]int, 0, numCourses)

	for _, courses := range prerequisites {
		in[courses[0]]++
		frees[courses[1]] = append(frees[courses[1]], courses[0])
	}

	for c, i := range in {
		if i == 0 {
			next = append(next, c)
		}
	}

	for i := 0; i != len(next); i++ {
		c := next[i]

		for _, v := range frees[c] {
			in[v]--
			if in[v] == 0 {
				next = append(next, v)
			}
		}
	}

	if len(next) == numCourses {
		return next
	}

	return []int{}
}

// @lc code=end

