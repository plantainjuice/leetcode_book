package main

import (
	"fmt"
)

func countPrimes(n int) int {
	res, isNotPrime := 0, make([]bool, n)

	for i := 2; i*i < n; i++ {
		if isNotPrime[i] {
			continue
		}

		for j := i * i; j < n; j = j + i {
			isNotPrime[j] = true
		}
	}

	for i := 2; i < n; i++ {
		if !isNotPrime[i] {
			res++
		}
	}

	return res
}

func main() {
	// res := rob([]int{1, 2, 3, 1})
	res := countPrimes(10)
	fmt.Println(res)
}
