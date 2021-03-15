/*
 * @lc app=leetcode id=216 lang=golang
 *
 * [216] Combination Sum III
 */

// @lc code=start
func combinationSum3(k int, n int) [][]int {
	if k == 0{
		return [][]int{}
	}
    
	c, res := []int{}, [][]int{}
	findCombinationSum3(k, n, 1, c, &res)

	return res
}

func findCombinationSum3(k int, target int, index int, c []int, res *[][]int){
	if target == 0{
		if len(c) == k{
			tmp := make([]int, len(c))
			copy(tmp, c)
			*res = append(*res, tmp)
		}
		return
	}

	for i := index; i < 10; i++{
		if i <= target{
			c = append(c, i)
			findCombinationSum3(k, target-i, i+1, c, res)
			c = c[:len(c)-1]
		}
	}
}
// @lc code=end

