package main

import (
	"fmt"
)

func nextPermutation(nums []int) {
	i, j := 0, 0
	for i = len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			break
		}
	}

	if i >= 0 {
		for j = len(nums) - 1; j > i; j-- {
			if nums[j] > nums[i] {
				swap(nums, i, j)
				break
			}
		}
	}

	reverse(nums, i+1, len(nums)-1)
}

func reverse(nums []int, i, j int) {
	for i < j {
		swap(nums, i, j)
		i++
		j--
	}
}

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func main() {
	res := []int{1, 3, 2}
	// res := []int{1, 2, 3}
	nextPermutation(res)
	fmt.Println(res)
}
