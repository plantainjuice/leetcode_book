/*
 * @lc app=leetcode id=207 lang=rust
 *
 * [207] Course Schedule
 */

// @lc code=start
impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let mut in_bound: Vec<i32> = vec![0; num_courses as usize];
        let mut edges: Vec<Vec<i32>> = vec![vec![]; num_courses as usize];
        let mut next: Vec<usize> = Vec::new();

        for i in prerequisites {
            in_bound[i[0] as usize] += 1;
            edges[i[1] as usize].push(i[0]);
        }

        for (i, v) in in_bound.iter().enumerate() {
            if *v == 0 {
                next.push(i);
            }
        }

        let mut i = 0;
        while i < next.len(){
            let cur = next[i];

            for v in &edges[cur] {
                let vv = *v as usize;
                in_bound[vv] -= 1;

                if in_bound[vv] == 0 {
                    next.push(vv);
                }
            }
            i+=1;
        }

        return next.len() == num_courses as usize;
    }
}
// @lc code=end
