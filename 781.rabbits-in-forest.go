/*
 * @lc app=leetcode id=781 lang=golang
 *
 * [781] Rabbits in Forest
 */

// @lc code=start
func numRabbits(answers []int) int {
	total, m := 0, make(map[int]int)
    
	for _, v := range answers{
		if m[v] == 0{
			m[v] = v
			total += v + 1
		}else{
			m[v]--
		}
	}

	return total
}
// @lc code=end

