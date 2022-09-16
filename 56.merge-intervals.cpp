/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> ans;
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (right >= intervals[i][0]) {
        right = max(right, intervals[i][1]);
      } else {
        ans.push_back({left, right});
        left = intervals[i][0];
        right = intervals[i][1];
      }
    }

    ans.push_back({left, right});

    return ans;
  }
};
// @lc code=end

