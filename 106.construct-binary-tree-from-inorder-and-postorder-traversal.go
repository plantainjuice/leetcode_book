/*
 * @lc app=leetcode id=106 lang=golang
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(inorder []int, postorder []int) *TreeNode {
	inpos := make(map[int]int)
	for i, v := range inorder {
		inpos[v] = i
	}

	return buildTreeDFS(inpos, inorder, postorder, 0, 0, len(postorder)-1)
}

func buildTreeDFS(inpos map[int]int, inorder, postorder []int, inStart, postStart, postEnd int) *TreeNode {
	if postStart > postEnd {
		return nil
	}
	root := postorder[postEnd]
	rootPos := inpos[root]

	leftLen := rootPos - inStart
	left := buildTreeDFS(inpos, inorder, postorder, inStart, postStart, postStart+leftLen-1)
	right := buildTreeDFS(inpos, inorder, postorder, rootPos+1, postStart+leftLen, postEnd-1)

	rootNode := &TreeNode{root, left, right}

	return rootNode
}

// @lc code=end
