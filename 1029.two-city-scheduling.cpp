/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(),
         [](const vector<int>& lhs, const vector<int>& rhs) {
           return (lhs[0] - lhs[1]) < (rhs[0] - rhs[1]);
         });

    int ans = 0;
    int n = costs.size() / 2;
    for (const vector<int>& c : costs) {
      if (n-- > 0)
        ans += c[0];
      else
        ans += c[1];
    }

    return ans;
  }
};
// @lc code=end

