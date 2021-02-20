/*
 * @lc app=leetcode id=54 lang=golang
 *
 * [54] Spiral Matrix
 */

// @lc code=start
func spiralOrder(matrix [][]int) []int {
	m := len(matrix)
	if m == 0 {
		return nil
	}

	n := len(matrix[0])
	if n == 0 {
		return nil
	}

	top, left, bottom, right := 0, 0, m-1, n-1
	count, sum, result := 0, m*n, make([]int, 0)

	for count < sum {
		i, j := top, left
		for j <= right && count < sum {
			result = append(result, matrix[i][j])
			j++
			count++
		}

		i, j = top+1, right
		for i <= bottom && count < sum {
			result = append(result, matrix[i][j])
			i++
			count++
		}

		i, j = bottom, right-1
		for j >= left && count < sum {
			result = append(result, matrix[i][j])
			j--
			count++
		}

		i, j = bottom-1, left
		for i > top && count < sum {
			result = append(result, matrix[i][j])
			i--
			count++
		}

		top, left, bottom, right = top+1, left+1, bottom-1, right-1
	}

	return result
}

// @lc code=end

