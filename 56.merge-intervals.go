/*
 * @lc app=leetcode id=56 lang=golang
 *
 * [56] Merge Intervals
 */

// @lc code=start

func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 || len(intervals) == 1 {
		return intervals
	}

	quickSort(intervals, 0, len(intervals)-1)
	res, curIndex := make([][]int, 0), 0
	res = append(res, intervals[0])

	for i := 1; i < len(intervals); i++ {
		if intervals[curIndex][1] < intervals[i][0] {
			curIndex = i
			res = append(res, intervals[i])
		} else {
			intervals[curIndex][1] = max(intervals[i][1], intervals[curIndex][1])
		}
	}

	return res
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func patitionSort(nums [][]int, lo, hi int) int {
	pivot := nums[hi]

	i := lo
	for j := lo; j < hi; j++ {
		if nums[j][0] < pivot[0] || (nums[j][0] == pivot[0] && nums[j][1] < pivot[1]) {
			nums[i], nums[j] = nums[j], nums[i]
			i++
		}
	}

	nums[i], nums[hi] = nums[hi], nums[i]

	return i
}

func quickSort(nums [][]int, lo, hi int) {
	if lo >= hi {
		return
	}

	p := patitionSort(nums, lo, hi)
	quickSort(nums, lo, p-1)
	quickSort(nums, p+1, hi)
}
// @lc code=end

