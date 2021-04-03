/*
 * @lc app=leetcode id=441 lang=golang
 *
 * [441] Arranging Coins
 */

// @lc code=start
import "math"
func arrangeCoins(n int) int {
    if n <=0 {
        return 0
    }

    res := math.Sqrt(2*float64(n)+0.25) - 0.5

    return int(res)
}
// @lc code=end
