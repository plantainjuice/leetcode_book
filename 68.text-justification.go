/*
 * @lc app=leetcode id=68 lang=golang
 *
 * [68] Text Justification
 */

// @lc code=start
func fullJustify(words []string, maxWidth int) []string {
	res := []string{}

	for index := 0; index < len(words); {
		line := ""
		count := len(words[index])
		last := index + 1

		for last < len(words) && count+len(words[last])+1 <= maxWidth {
			count += len(words[last]) + 1
			last++
		}

		diff := last - index - 1
		if last == len(words) || diff == 0 {
			for i := index; i < last; i++ {
				line = line + words[i] + " "
			}

			line = line[:len(line)-1]

			for i := len(line) + 1; i <= maxWidth; i++ {
				line = line + " "
			}
		} else {
			spaces := (maxWidth - count) / diff
			left := (maxWidth - count) % diff

			for i := index; i < last; i++ {
				line = line + words[i]
				if i < last-1 {
					space := spaces
					if i-index < left {
						space = spaces + 1
					}
					for j := 0; j <= space; j++ {
						line = line + " "
					}
				}
			}
		}

		fmt.Println(line, len(line))
		res = append(res, line)
		index = last
	}

	return res
}

// @lc code=end
