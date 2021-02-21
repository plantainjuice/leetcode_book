/*
 * @lc app=leetcode id=303 lang=golang
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start

// prefix sum
type NumArray struct {
	prefixSum []int
}


func Constructor(nums []int) NumArray {
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i-1]
	}
	return NumArray{prefixSum: nums}
}


func (this *NumArray) SumRange(i int, j int) int {
	if i > 0{
		return this.prefixSum[j] - this.prefixSum[i-1]
	}
	return this.prefixSum[j]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
// @lc code=end

