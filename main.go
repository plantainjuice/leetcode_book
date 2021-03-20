package main

import (
	"fmt"
)

func hIndex(citations []int) int {
	low, high := 0, len(citations) - 1

	for low <= high {
		mid := low + (high-low)>>1
		if len(citations)-mid > citations[mid] {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return len(citations) - low
}

func main() {
	res := hIndex([]int{0, 1, 3, 5, 6})

	fmt.Println(res)
}
