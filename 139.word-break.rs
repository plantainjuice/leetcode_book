/*
 * @lc app=leetcode id=139 lang=rust
 *
 * [139] Word Break
 */

// @lc code=start
impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let n = s.len();
        let mut dp = vec![false; n+1];
        dp[0] = true;

        for i in 0..n{
            if !dp[i] {
                continue;
            }

            for word in &word_dict{
                let size = word.len();
                if i + size <= n && word.eq(&s.chars().skip(i).take(size).collect::<String>()){
                    dp[i + size] = true;
                }
            }
        }

        dp[n]
        
    }
}
// @lc code=end
