/*
 * @lc app=leetcode id=167 lang=golang
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
func twoSum(numbers []int, target int) []int {
	i, j := 0, len(numbers)-1

	for i < j {
		if numbers[i] == target-numbers[j] {
			return []int{i + 1, j + 1}
		} else if numbers[i] < target-numbers[j] {
			i++
		} else {
			j--
		}
	}

	return []int{-1, -1}

}

// @lc code=end
