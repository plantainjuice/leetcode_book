/*
 * @lc app=leetcode id=6 lang=rust
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let n = s.len();
        let mut matrix = vec![vec![]; num_rows as usize];
        let (mut index, mut down, mut up) = (0, 0, num_rows-2);

        while index < n{
            if down < num_rows{
                matrix[down as usize].push(s.get(index..index+1).unwrap());
                down += 1;
                index += 1;
            }else if up > 0{
                matrix[up as usize].push(s.get(index..index+1).unwrap());
                up -= 1;
                index += 1;
            }else{
                down = 0;
                up = num_rows-2;
            }
        }

        let mut res = "".to_string();
        for row in matrix{
            for item in row{
                res.push_str(item);
            }
        }
        
        res
    }
}
// @lc code=end
