/*
 * @lc app=leetcode id=17 lang=golang
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
var dict = map[string][]string{
    "2" : []string{"a","b","c"},
    "3" : []string{"d", "e", "f"},
    "4" : []string{"g", "h", "i"},
    "5" : []string{"j", "k", "l"},
    "6" : []string{"m", "n", "o"},
    "7" : []string{"p", "q", "r", "s"},
    "8" : []string{"t", "u", "v"},
    "9" : []string{"w", "x", "y", "z"},
}

func letterCombinations(digits string) []string {
    res := []string{}

    if digits != ""{
        letterCombinationsDFS(digits, "", &res)
    }

    return res
}

func letterCombinationsDFS(digits string, combine string, result *[]string){
    if digits == ""{
        *result = append(*result, combine)
        return
    }

    num := digits[0:1]
    digits = digits[1:]
    for _, c := range dict[num] {
        combine += c
        letterCombinationsDFS(digits, combine, result)
        combine = combine[0: len(combine) - 1]
    }
}
// @lc code=end
