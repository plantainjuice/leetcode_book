/*
 * @lc app=leetcode id=90 lang=golang
 *
 * [90] Subsets II
 */

// @lc code=start
func subsetsWithDup(nums []int) [][]int {
	cur, res := []int{}, [][]int{}
	sort.Ints(nums)

	for k := 0; k <= len(nums); k++ {
		generateSubsetWithDup(nums, k, 0, cur, &res)
	}

	return res
}

func generateSubsetWithDup(nums []int, k, start int, cur []int, res *[][]int) {
	if len(cur) == k {
		tmp := make([]int, len(cur))
		copy(tmp, cur)
		*res = append(*res, tmp)
		return
	}

	for i := start; i < len(nums); i++ {
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		cur = append(cur, nums[i])
		generateSubsetWithDup(nums, k, i+1, cur, res)
		cur = cur[:len(cur)-1]
	}
}

// @lc code=end
