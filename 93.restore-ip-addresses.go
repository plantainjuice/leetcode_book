/*
 * @lc app=leetcode id=93 lang=golang
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
func restoreIpAddresses(s string) []string {
	if len(s) == 0{
		return []string{}
	}

	ip, res := []int{}, []string{}
	dfs(s, 0, ip, &res)

	return res
}

func dfs(s string, index int, ip []int, res *[]string) {
	if index == len(s) {
		if len(ip) == 4 {
			*res = append(*res, toIpString(ip))
		}
		return
	}

	next, _ := strconv.Atoi(string(s[index]))
	if index == 0{
		ip = append(ip, next)
		dfs(s, index+1, ip, res)
		return
	}

	plus := ip[len(ip)-1]*10 + next
	if plus <= 255 && ip[len(ip) - 1] != 0 {
		ip[len(ip)-1] = plus
		dfs(s, index+1, ip, res)
		ip[len(ip)-1] /= 10
	}
	if len(ip) < 4 {
		ip = append(ip, next)
		dfs(s, index+1, ip, res)
		ip = ip[:len(ip) -1]
	}
}

func toIpString(ip []int) string {
	res := strconv.Itoa(ip[0])
	for i := 1; i < len(ip); i++ {
		res += "." + strconv.Itoa(ip[i])
	}

	return res
}
// @lc code=end

