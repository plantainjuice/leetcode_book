/*
 * @lc app=leetcode id=60 lang=golang
 *
 * [60] Permutation Sequence
 */

// @lc code=start
import (
	"strconv"
)

func getPermutation(n int, k int) string {
	if k == 0{
		return ""
	}

	index, perm, used, res := k, make([]int, 0), make([]bool, n+1), ""
	findPermutation(n, &index, 0, perm, &used, &res)

	return res
}

func findPermutation(n int, k *int, depth int, perm []int, used *[]bool, res *string){
	if depth == n{
		*k--
		if *k == 0{
			for _, p := range perm{
				*res += strconv.Itoa(p)
			}
		}
		return
	}

	for i := 1; i <= n; i++{
		if (*used)[i] == true{
			continue
		}

		(*used)[i] = true
		perm = append(perm, i)
		findPermutation(n, k, depth+1, perm, used, res)
		perm = perm[:len(perm)-1]
		(*used)[i] = false
	}
}

// @lc code=end

