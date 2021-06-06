/*
 * @lc app=leetcode id=140 lang=rust
 *
 * [140] Word Break II
 */

// @lc code=start
use std::collections::HashSet;
use std::collections::HashMap;

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> Vec<String> {
        let word_set: HashSet<String> = word_dict.into_iter().collect();
        let mut memorize: HashMap<String, Vec<String>> = HashMap::new();
        Self::_word_break_helper(s, &word_set, &mut memorize)
    }

    fn _word_break_helper(s: String, word_set: &HashSet<String>, memorize: &mut HashMap<String, Vec<String>>) -> Vec<String>{
        if memorize.contains_key(&s) {
            return memorize[&s].clone();
        }

        let l = s.len();
        let mut ans: Vec<String> = vec![];

        if word_set.contains(&s){
            ans.push(s.clone());
        }

        for j in 1..l{
            let right = &s[j..l];

            if !word_set.contains(&right.to_string()){
                continue;
            }

            let left = &s[0..j];
            let left_ans = Self::_word_break_helper(left.to_string(), word_set, memorize);

            ans.append(&mut Self::_append(left_ans, right.to_string()));
        }

        memorize.insert(s, ans.clone());
        return ans;
    }

    fn _append(prefixes: Vec<String>, word: String) -> Vec<String>{
        let mut res: Vec<String> = vec![];
        for prefix in prefixes{
            res.push(prefix + " " + &word);
        }
        res
    }

}
// @lc code=end
