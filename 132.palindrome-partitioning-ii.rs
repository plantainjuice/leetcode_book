/*
 * @lc app=leetcode id=132 lang=rust
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
impl Solution {
    pub fn min_cut(s: String) -> i32 {
        let n = s.len();
        if n == 0 || n == 1{
            0;
        }

        let mut dp = vec![std::i32::MAX; (n + 1) as usize];
        dp[0] = 0;
        
        for i in 1..n+1{
            for j in 0..i{
                if Self::is_palindrome(s.get(j..i).unwrap()){
                    dp[i] = std::cmp::min(dp[i], dp[j]+1)
                }
            }
        }

        dp[n] - 1
    }

    fn is_palindrome(s: &str) -> bool{
        let mut low = 0;
        let mut high = s.len() - 1;

        while low < high {
            if s.get(low..low+1).unwrap() != s.get(high..high+1).unwrap(){
                return false;
            }
            low+=1;
            high-=1;
        }
        true
    }
}
// @lc code=end
