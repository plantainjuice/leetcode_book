/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) return a[1] < b[1];
      return a[0] > b[0];
    };
    sort(people.begin(), people.end(), cmp);

    vector<vector<int>> ans;
    for (int i = 0; i < people.size(); ++i) {
      int pos = people[i][1];
      ans.insert(ans.begin() + pos, people[i]);
    }

    return ans;
  }
};
// @lc code=end

