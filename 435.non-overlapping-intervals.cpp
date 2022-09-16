/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return 0;

    auto cmp = [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; };
    sort(intervals.begin(), intervals.end(), cmp);

    int non_overlap = 1;
    int last_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      // no overlap
      if (last_end <= intervals[i][0]) {
        last_end = intervals[i][1];
        ++non_overlap;
      }
    }

    return intervals.size() - non_overlap;
  }
};
// @lc code=end

