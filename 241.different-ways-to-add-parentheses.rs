/*
 * @lc app=leetcode id=241 lang=rust
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
impl Solution {
    pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
        let mut memo = std::collections::HashMap::<String, Vec<i32>>::new();
        return Self::way(&mut memo, expression);
    }

    fn way(memo: &mut std::collections::HashMap::<String, Vec<i32>>, expression: String) -> Vec<i32>{
        if memo.contains_key(&expression){
            return memo.get_mut(&expression).unwrap().to_vec();
        }

        let mut ans = vec![];
        let len = expression.len();

        for i in 0..len{
            let op = expression.get(i..i+1).unwrap();


            if op == "+" || op == "-" || op == "*"{
                let left = expression.get(0..i).unwrap().to_string();
                let right = expression.get(i+1..len).unwrap().to_string();

                let l_ans = Self::way(memo, left);
                let r_ans = Self::way(memo, right);

                let f :fn(i32, i32) -> i32;

                match op {
                    "+" => f = |a, b| a + b,
                    "-" => f = |a, b| a - b,
                    "*" => f = |a, b| a * b,
                    _ => panic!(""),
                }

                for a in &l_ans{
                    for b in &r_ans{
                        ans.push(f(*a, *b));
                    }
                }
            }
        }

        if ans.len() == 0{
            ans.push(expression.parse::<i32>().unwrap());
        }

        memo.insert(expression, ans.clone());
        return ans;
    }
}
// @lc code=end
