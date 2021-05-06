/*
 * @lc app=leetcode id=289 lang=rust
 *
 * [289] Game of Life
 */

// @lc code=start
impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        if board.len() == 0{
            return ;
        }

        let m = board.len();
        let n = board[0].len();

        for i in 0..m{
            for j in 0..n{
                let mut neighbour = 0;

                for di in 0..3{
                    for dj in 0..3{
                        if i+di>=1 && i+di<=m && j+dj>=1 && j+dj<=n && !(di == 1 && dj == 1) {
                            neighbour += board[i+di-1][j+dj-1] & 0b01;
                        }
                    }
                }

                // use 2 bits represent next state & current state。
                if board[i][j] == 1{
                    if neighbour < 2 || neighbour > 3{
                        board[i][j] = 0b01;
                    }else{
                        board[i][j] = 0b11;
                    }
                }else{
                    if neighbour == 3{
                        board[i][j] = 0b10;
                    }else{
                        board[i][j] = 0b00;
                    }
                }
            }
        }

        for i in 0..m{
            for j in 0..n{
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
}
// @lc code=end
