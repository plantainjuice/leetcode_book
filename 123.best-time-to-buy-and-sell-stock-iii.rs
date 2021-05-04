/*
 * @lc app=leetcode id=123 lang=rust
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
use std::vec::Vec;
use std::cmp::{max, min};

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        if n == 0 {
            return 0
        }

        let mut min_price = prices[0];
        let mut f = vec![0; n];
        f[0] = 0;
        
        for i in 1..n{
            f[i] = f[i-1];
            // prevent less than 0
            if prices[i] > min_price{
                f[i] = max(f[i], prices[i] - min_price);
            }
            min_price = min(min_price, prices[i]);
        }

        let mut res = f[n-1];
        let mut max_price = std::i32::MIN;
        for i in (1..n).rev(){
            // prevent less than 0
            if prices[i] < max_price{
                res = max(res, max_price - prices[i] + f[i-1]);
            }
            max_price = max(max_price, prices[i]);
        }

        res
    }
}
// @lc code=end
