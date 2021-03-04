/*
 * @lc app=leetcode id=202 lang=golang
 *
 * [202] Happy Number
 */

// @lc code=start
func isHappy(n int) bool {
	res, num, record := 0, n, map[int]int{}

	for {
		for num > 0 {
			res += (num % 10) * (num % 10)
			num = num / 10
		}

		if _, ok := record[res]; !ok{
			if res == 1{
				return true
			}
			record[res] = res
			num = res
			res = 0
		}else{
			return false
		}
	}
    
}
// @lc code=end

