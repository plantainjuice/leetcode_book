package main

import (
	"fmt"
)

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

func main() {
	matrix := [][]int{
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5},
	}
	obj := Constructor(matrix)
	res := obj.SumRegion(2, 1, 4, 3)
	fmt.Println(res)
}
