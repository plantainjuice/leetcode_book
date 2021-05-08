/*
 * @lc app=leetcode id=393 lang=rust
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
impl Solution {
    pub fn valid_utf8(data: Vec<i32>) -> bool {
        let mut cnt = 0;
        for hex in data{
            if cnt == 0{
                if hex >> 3 == 0b11110{
                    cnt = 3;
                }else if hex >> 4 == 0b1110{
                    cnt = 2;
                }else if hex >> 5 == 0b110{
                    cnt = 1;
                }else if hex >> 7 == 0b1{
                    return false;
                }
            }else{
                if hex >> 6 != 0b10{
                    return false;
                }
                cnt = cnt - 1;
            }
        }

        return cnt == 0;
    }
}
// @lc code=end
