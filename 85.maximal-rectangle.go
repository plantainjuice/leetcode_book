/*
 * @lc app=leetcode id=85 lang=golang
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}

	res, n, m, heights := 0, len(matrix), len(matrix[0]), make([]int, len(matrix[0])+1)
	heights[m] = -1

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == '1' {
				heights[j]++
			} else {
				heights[j] = 0
			}
		}

		stack := make([]int, m+1)
		for j := 0; j <= m; j++ {
			for len(stack) != 0 && heights[j] < heights[stack[len(stack)-1]] {
				top := stack[len(stack)-1]
				stack = stack[:len(stack)-1] // pop

				if len(stack) == 0 {
					res = max(res, heights[top]*j)
				} else {
					res = max(res, heights[top]*(j-stack[len(stack)-1]-1))
				}
			}

			stack = append(stack, j)
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

// @lc code=end
