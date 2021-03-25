package main

import (
	"fmt"
)

func trap(height []int) int {
	res, left, right, leftmax, rightmax := 0, 0, len(height)-1, 0, 0

    if len(height) <= 2{
        return 0
    }

	for left < right {
		if height[left] <= height[right] {
			if height[left] > leftmax {
				leftmax = height[left]
			} else {
				res += leftmax - height[left]
			}

            left++
		} else {
			if height[right] > rightmax {
				rightmax = height[right]
			} else {
				res += rightmax - height[right]
			}

            right--
		}
	}

    return res
}

func main() {
	res := trap([]int{1, 2})
	fmt.Println(res)
}
