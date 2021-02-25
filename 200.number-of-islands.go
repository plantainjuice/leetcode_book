/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 */

// @lc code=start
var directions = [4][2]int{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func numIslands(grid [][]byte) int {
	m := len(grid)
	if m == 0 {
		return 0
	}

	n := len(grid[0])
	if n == 0 {
		return 0
	}

	res, visited := 0, make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' && !visited[i][j] {
				searchIsland(grid, visited, i, j)
				res++
			}
		}
	}

	return res
}

func isValid(grid [][]byte, x, y int) bool {
	m, n := len(grid), len(grid[0])
	return x >= 0 && y >= 0 && x < m && y < n
}

func searchIsland(grid [][]byte, visited [][]bool, x, y int) {
	visited[x][y] = true

	for _, dir := range directions {
		nx := x + dir[0]
		ny := y + dir[1]

		if isValid(grid, nx, ny) && !visited[nx][ny] && grid[nx][ny] == '1' {
			searchIsland(grid, visited, nx, ny)
		}
	}
}

// @lc code=end

