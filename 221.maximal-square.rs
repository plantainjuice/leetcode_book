/*
 * @lc app=leetcode id=221 lang=rust
 *
 * [221] Maximal Square
 */

// @lc code=start
impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.len() == 0{
            return 0;
        }

        let m = matrix.len();
        let n = matrix[0].len();
        let mut sizes = vec![vec![0i32; n]; m];

        let mut ans = 0;

        for i in 0..m{
            for j in 0..n{
                sizes[i][j] = matrix[i][j] as i32 - '0' as i32;

                if sizes[i][j] == 0{
                    continue;
                }

                if i == 0 || j == 0 {
                    // do nothing
                }else if i == 0{
                    sizes[i][j] = sizes[i][j-1] + 1;
                }else if j == 0{
                    sizes[i][j] = sizes[i-1][j] + 1;
                }else{
                    use std::cmp::min;
                    sizes[i][j] = min(min(sizes[i][j-1], sizes[i-1][j]), sizes[i-1][j-1]) + 1;
                }
                ans = std::cmp::max(ans, sizes[i][j] * sizes[i][j]);
            }
        }

        ans
    }
}
// @lc code=end
