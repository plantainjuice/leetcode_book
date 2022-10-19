/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
 public:
  int countStudents(vector<int>& A, vector<int>& B) {
    int n = A.size();
    array<int,2> cnt = {0, 0};
    for(int a : A) ++cnt[a];

    int k = 0;
    for(; k < n && cnt[B[k]] > 0; k++) {
      --cnt[B[k]];
    }

    return n - k;
  }
};
// @lc code=end

