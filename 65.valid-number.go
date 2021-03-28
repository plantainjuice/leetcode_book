/*
 * @lc app=leetcode id=65 lang=golang
 *
 * [65] Valid Number
 */

// @lc code=start
func isNumber(s string) bool {
	s = strings.Trim(s, " ")
	numberSeen := false
	eSeen := false
	dotSeen := false

	for i := 0; i < len(s); i++ {
		c := s[i]
		if c <= '9' && c >= '0' {
			numberSeen = true
		}else if c == '.' {
			if eSeen || dotSeen {
				return false
			}
			dotSeen = true
		}else if c == 'e' || c == 'E'{
			if eSeen || !numberSeen{
				return false
			}
			numberSeen = false
			eSeen = true
		}else if c == '-' || c == '+'{
			if i != 0 && s[i-1] != 'e'{
				return false
			}
		}else {
			return false
		}

	}
    
	return numberSeen
}
// @lc code=end
