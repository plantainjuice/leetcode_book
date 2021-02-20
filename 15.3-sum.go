/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 */
import (
	"sort"
)

// @lc code=start
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result, start, end, addSum, length := make([][]int, 0), 0, 0, 0, len(nums)

	for index := 1; index < length-1; index++ {
		start, end = 0, length-1

		if index > 1 && nums[index-1] == nums[index] {
			start = index - 1
		}

		for start < index && end > index {
			if start > 0 && nums[start] == nums[start-1] {
				start++
				continue
			}

			if end < length-1 && nums[end] == nums[end+1] {
				end--
				continue
			}

			addSum = nums[start] + nums[index] + nums[end]

			if addSum == 0 {
				result = append(result, []int{nums[start], nums[index], nums[end]})
				start++
				end--
			} else if addSum > 0 {
				end--
			} else {
				start++
			}

		}

	}

	return result
}

// @lc code=end

