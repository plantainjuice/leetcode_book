package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}

    left := root.Left
    right := root.Right

	root.Left = invertTree(right)
	root.Right = invertTree(left)

	return root
}

func main() {
	root := &TreeNode{4,
		&TreeNode{2, &TreeNode{1, nil, nil}, &TreeNode{3, nil, nil}},
		&TreeNode{7, &TreeNode{6, nil, nil}, &TreeNode{9, nil, nil}}}

	res := invertTree(root)
	fmt.Println(res.Val, res.Left, res.Right, res.Left.Left)
}
