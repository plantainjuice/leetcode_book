/*
 * @lc app=leetcode id=81 lang=golang
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
func search(nums []int, target int) bool {
	if len(nums) == 0 {
		return false
	}

	low, high := 0, len(nums)-1

	for low <= high {
		mid := low + (high-low)>>1

		if nums[mid] == target {
			return true
		}

		if nums[mid] > nums[low] {
			if nums[low] <= target && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else if nums[mid] < nums[high] {
			if nums[mid] < target && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		} else {
			if nums[low] == nums[mid] {
				low++
			}

			if nums[high] == nums[mid] {
				high--
			}
		}
	}

	return false
}

// @lc code=end
