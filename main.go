package main

import (
	"fmt"
)

func majorityElement(nums []int) int {
	res, count := nums[0], 0

	for _, num := range nums {
		if count == 0 {
			res, count = num, 1
		} else {
			if num == res {
				count++
			} else {
				count--
			}
		}
	}

	return res
}

func main() {
	res := majorityElement([]int{3, 2, 3})
	fmt.Println(res)
}
