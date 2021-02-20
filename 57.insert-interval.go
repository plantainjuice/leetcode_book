/*
 * @lc app=leetcode id=57 lang=golang
 *
 * [57] Insert Interval
 */

// @lc code=start
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func insert(intervals [][]int, newInterval []int) [][]int {
	result, curIndex := make([][]int, 0), 0

	if len(intervals) == 0 {
		result = append(result, newInterval)
		return result
	}

	for curIndex < len(intervals) && intervals[curIndex][1] < newInterval[0] {
		result = append(result, intervals[curIndex])
		curIndex++
	}

	for curIndex < len(intervals) && intervals[curIndex][0] <= newInterval[1] {
		newInterval = []int{min(intervals[curIndex][0], newInterval[0]), max(intervals[curIndex][1], newInterval[1])}
		curIndex++
	}

	result = append(result, newInterval)

	for curIndex < len(intervals) {
		result = append(result, intervals[curIndex])
		curIndex++
	}

	return result
}

// @lc code=end

