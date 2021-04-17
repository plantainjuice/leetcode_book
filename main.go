package main

import (
	"fmt"
)

func isPowerOfThree(n int) bool {
	for n >= 3 {
		if n%3 == 0 {
			n = n / 3
		} else {
			return false
		}
	}

	return n == 1
}

func main() {
	res := isPowerOfThree(28)
	fmt.Println(res)
}
