/*
 * @lc app=leetcode id=126 lang=rust
 *
 * [126] Word Ladder II
 */

// @lc code=start
use std::collections::HashSet;
use std::collections::HashMap;
use std::collections::VecDeque;

impl Solution {
    pub fn find_ladders(begin_word: String, end_word: String, word_list: Vec<String>) -> Vec<Vec<String>> {
        let mut word_set: HashSet<String> = word_list.into_iter().collect();
        if !word_set.contains(&end_word) {
            return vec![];
        }
        word_set.remove(&begin_word);
        word_set.remove(&end_word);

        let mut steps: HashMap<String, i32> = HashMap::new();
        let mut parents: HashMap<String, Vec<String>> = HashMap::new();
        let mut q: VecDeque<String> = VecDeque::new();
        steps.insert(begin_word.clone(), 1);
        q.push_back(begin_word.clone());

        let mut ans: Vec<Vec<String>> = Vec::new();
        let mut found = false;
        let mut step = 0;
        let l = begin_word.len();

        while q.len() != 0 && !found{
            step += 1;
            for _size in 0..q.len(){
                let p = q.pop_front().unwrap();
                let mut w = p.clone();

                for i in 0..l{
                    let ch = w.as_bytes()[i] as char;
                    for j in 97u8..124u8{
                        let j = j as char;
                        if j == ch {
                            continue;
                        }
                        w = Self::change_string_at(w, i, j);

                        if w == end_word{
                            parents.entry(end_word.clone()).and_modify(|pa| pa.push(p.clone())).or_insert(vec![p.clone()]);
                            found = true;
                        }else {
                            if steps.contains_key(&w) && step < steps[&w]{
                                parents.entry(w.clone()).and_modify(|pa| pa.push(p.clone())).or_insert(vec![p.clone()]);
                            }
                        }

                        if !word_set.contains(&w){
                            continue;
                        }

                        let p_step = steps[&p];

                        word_set.remove(&w);
                        q.push_back(w.clone());
                        steps.entry(w.clone()).and_modify(|s| *s += 1).or_insert(p_step + 1);
                        parents.entry(w.clone()).and_modify(|pa| pa.push(p.clone())).or_insert(vec![p.clone()]);
                    }
                    w = Self::change_string_at(w, i, ch);
                }

            }
        }

        if found{
            let mut curr: Vec<String> = vec![end_word.clone()];
            Self::get_paths(&end_word, &begin_word, &parents, &mut curr, &mut ans);
        }

        return ans;
    }

    fn get_paths(word: &String,
                begin_word: &String,
                parents: &HashMap<String, Vec<String>>,
                curr: &mut Vec<String>,
                ans: &mut Vec<Vec<String>>){

        if word == begin_word{
            let mut tmp = curr.clone();
            tmp.reverse();
            ans.push(tmp.to_vec());
            return;
        }

        for p in parents.get(word).unwrap(){
            curr.push(p.to_string());
            Self::get_paths(p, begin_word, parents, curr, ans);
            curr.pop();
        }
    }

    fn change_string_at(s: String, index: usize, ch: char) -> String{
        let iter = s.chars();
        let mut new = String::new();

        for (i, mut c) in iter.enumerate() {
            if i == index { c = ch; }
            new.push(c);
        }

        new
    }
}
// @lc code=end
