/*
 * @lc app=leetcode id=12 lang=rust
 *
 * [12] Integer to Roman
 */

// @lc code=start
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;

        let values = vec![1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let symbols = vec!["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

        let mut res = vec![];
        
        for i in 0..13 {
            let mut c = num / values[i];
            num = num % values[i];
            
            while c > 0{
                res.push(symbols[i]);
                c -= 1;
            }

        }

        res.into_iter().collect()
    }
}
// @lc code=end
