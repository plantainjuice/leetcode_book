package main

import (
	"fmt"
)

func singleNumber(nums []int) int {
	ones, twos := 0, 0
	for _, n := range nums {
		ones = (ones ^ n) & ^twos
		twos = (twos ^ n) & ^ones
	}

	return ones
}

func main() {
	// res := rob([]int{1, 2, 3, 1})
	res := singleNumber([]int{2, 2, 3, 2})
	fmt.Println(res)
}
