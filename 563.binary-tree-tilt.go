/*
 * @lc app=leetcode id=563 lang=golang
 *
 * [563] Binary Tree Tilt
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
// @lc code=end
