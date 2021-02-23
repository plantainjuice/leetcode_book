package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	return isValidbst(root, math.MinInt32, math.MaxInt32)
}

func isValidbst(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}

	v := root.Val

	return v <= max && v >= min && isValidbst(root.Left, min, v) && isValidbst(root.Right, v, max)
}

func main() {
	res := isValidBST(&TreeNode{1, nil, nil})
	fmt.Println(res)
}
