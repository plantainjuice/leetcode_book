/*
 * @lc app=leetcode id=98 lang=golang
 *
 * [98] Validate Binary Search Tree
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
 func isValidBST(root *TreeNode) bool {
	return isValidbst(root, math.MinInt64, math.MaxInt64)
}

func isValidbst(root *TreeNode, min, max int64) bool {
	if root == nil {
		return true
	}

	v := int64(root.Val)

	return v < max && v > min && isValidbst(root.Left, min, v) && isValidbst(root.Right, v, max)
}
// @lc code=end

