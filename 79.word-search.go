/*
 * @lc app=leetcode id=79 lang=golang
 *
 * [79] Word Search
 */

// @lc code=start
var dir = [][]int{
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, 1},
}

func exist(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])
	visited := make([][]bool, m)
	for i := 0; i < len(visited); i++ {
		visited[i] = make([]bool, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if searchWord(board, visited, word, 0, i, j) {
				return true
			}
		}
	}

	return false
}

func isInBoard(board [][]byte, x, y int) bool {
	m, n := len(board), len(board[0])
	return x >= 0 && y >= 0 && x < m && y < n
}

func searchWord(board [][]byte, visited [][]bool, word string, index, x, y int) bool {
	if index == len(word)-1 {
		return word[index] == board[x][y]
	}

	if word[index] == board[x][y] {
		visited[x][y] = true

		for _, d := range dir {
			nx := x + d[0]
			ny := y + d[1]
			if isInBoard(board, nx, ny) && !visited[nx][ny] && searchWord(board, visited, word, index+1, nx, ny) {
				return true
			}
		}

		visited[x][y] = false
	}

	return false
}

// @lc code=end
