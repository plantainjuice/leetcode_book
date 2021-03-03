package main

import (
	"fmt"
)

func sortColors(nums []int) {
	if len(nums) == 0 {
		return
	}

	r, w, b := 0, 0, 0

	for _, num := range nums {
		if num == 0 {
			nums[b] = 2
			b++
			nums[w] = 1
			w++
			nums[r] = 0
			r++
		} else if num == 1 {
			nums[b] = 2
			b++
			nums[w] = 1
			w++
		} else if num == 2 {
			b++
		}
	}
}

func main() {
	res := []int{2, 0, 2, 1, 1, 0}
	sortColors(res)
	fmt.Println(res)
}
