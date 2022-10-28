/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in(n);
    vector<int> out(n);

    for (auto& t : trust) {
      int a = t[0] - 1;
      int b = t[1] - 1;
      in[b]++;
      out[a]++;
    }

    for (int i = 0; i < n; ++i)
      if (in[i] == n - 1 && out[i] == 0) return i + 1;

    return -1;
  }
};
// @lc code=end

