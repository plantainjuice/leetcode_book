/*
 * @lc app=leetcode id=74 lang=golang
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix) == 0 || len(matrix[0]) == 0{
        return false
    }
    m, low, high := len(matrix[0]), 0, len(matrix) * len(matrix[0]) - 1

    for low <= high {
        mid := low + (high - low)>> 1
        val := matrix[mid/m][mid%m]
        if val == target{
            return true
        }

        if val > target{
            high = mid - 1
        }else{
            low = mid + 1
        }
    }

    return false
}
// @lc code=end
