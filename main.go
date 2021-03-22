package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTilt(root *TreeNode) int {
	if root == nil {
		return 0
	}

    sum := 0
    findTiltDFS(root, &sum)

    return sum
}

func findTiltDFS(root *TreeNode, sum *int)int{
    if root == nil {
        return 0
    }

	left := findTiltDFS(root.Left, sum)
	right := findTiltDFS(root.Right, sum)
	*sum += int(abs(float64(left) - float64(right)))

	return root.Val + left + right
}


func abs(n float64) float64 {
	if n < 0 {
		return -n
	}

	return n
}

func main() {
	root := &TreeNode{1,
		&TreeNode{2, nil, nil},
		&TreeNode{3, nil, nil}}

	res := findTilt(root)
	fmt.Println(res)
}
