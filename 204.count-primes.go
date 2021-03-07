/*
 * @lc app=leetcode id=204 lang=golang
 *
 * [204] Count Primes
 */

// @lc code=start
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

// @lc code=end
