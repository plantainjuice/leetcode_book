/*
 * @lc app=leetcode id=303 lang=golang
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
type NumArray struct {
	nums []int
}


func Constructor(nums []int) NumArray {
	return NumArray{nums: nums}
}


func (this *NumArray) SumRange(i int, j int) int {
	sum := 0
	for i <= j && i < len(this.nums){
		sum += this.nums[i]
		i++
	}

	return sum
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
// @lc code=end

