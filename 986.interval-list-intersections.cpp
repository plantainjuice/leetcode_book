/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> ans;
    for (int i = 0, j = 0; i < A.size() && j < B.size();) {
      int start = max(A[i][0], B[j][0]);
      int end = min(A[i][1], B[j][1]);
      if (start <= end) ans.push_back({start, end});

      A[i][1] < B[j][1] ? ++i : ++j;
    }

    return ans;
  }
};
// @lc code=end

