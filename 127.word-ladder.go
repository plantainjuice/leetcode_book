/*
 * @lc app=leetcode id=127 lang=golang
 *
 * [127] Word Ladder
 */

// @lc code=start
func ladderLength(beginWord string, endWord string, wordList []string) int {
	res, wordMap, queue := 0, getWordMap(wordList, beginWord), []string{beginWord}

	for len(queue) > 0 {
		res++
		qlen := len(queue)
		
		for i := 0; i < qlen; i++ {
			top := queue[0]
			queue = queue[1:]
			for _, next := range getNextWords(top) {
				if _, ok := wordMap[next]; ok {
					if next == endWord {
						return res + 1
					}

					delete(wordMap, next)
					queue = append(queue, next)
				}
			}
		}
	}

	return 0
}

func getWordMap(wordList []string, beginWord string) map[string]bool {
	wordMap := make(map[string]bool)

	for _, word := range wordList {
		if word != beginWord {
			wordMap[word] = true
		}
	}

	return wordMap
}

func getNextWords(word string) []string {
	res := []string{}

	for i := 0; i < 26; i++ {
		for j := 0; j < len(word); j++ {
			tmp := 'a' + i
			if byte(tmp) != word[j] {
				res = append(res, word[0:j]+string(tmp)+word[j+1:])
			}
		}
	}

	return res
}

// @lc code=end

