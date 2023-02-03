/*
 * @lc app=leetcode id=429 lang=golang
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
	ans := make([][]int, 0)

	var dfs func(*Node, int)
	dfs = func(node *Node, index int) {
		if node == nil {
			return
		}

		if index == len(ans) {
			ans = append(ans, []int{node.Val})
		} else {
			ans[index] = append(ans[index], node.Val)
		}

		for _, child := range node.Children {
			dfs(child, index+1)
		}
	}

	dfs(root, 0)

	return ans
}

// @lc code=end

