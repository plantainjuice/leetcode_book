/*
 * @lc app=leetcode id=304 lang=golang
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
type NumMatrix struct {
	matrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	return NumMatrix{matrix: matrix}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	if len(this.matrix) == 0 || len(this.matrix[0]) == 0 {
		return 0
	}

	sum, i, j, m, n := 0, row1, col1, len(this.matrix), len(this.matrix[0])

	for ; i <= row2 && i <= m; i++ {
		for j = col1; j <= col2 && j <= n; j++ {
			sum += this.matrix[i][j]
		}
	}

	return sum
}
/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
// @lc code=end

