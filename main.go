package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	inPos := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		inPos[inorder[i]] = i
	}

	return buildTreeDFS(preorder, 0, len(preorder)-1, 0, inPos)
}

func buildTreeDFS(pre []int, preStart int, preEnd int, inStart int, inPos map[int]int) *TreeNode {
	if preStart > preEnd {
		return nil
	}

	root := &TreeNode{Val: pre[preStart]}
	rootIdx := inPos[pre[preStart]]
	leftLen := rootIdx - inStart

	root.Left = buildTreeDFS(pre, preStart+1, preStart+leftLen, inStart, inPos)
	root.Right = buildTreeDFS(pre, preStart+leftLen+1, preEnd, rootIdx+1, inPos)

	return root
}

func main() {
	res := buildTree([]int{3, 9, 20, 15, 7}, []int{9, 3, 15, 20, 7})
	fmt.Println(res)
}
