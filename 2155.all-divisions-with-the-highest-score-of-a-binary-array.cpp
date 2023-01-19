/*
 * @lc app=leetcode id=2155 lang=cpp
 *
 * [2155] All Divisions With the Highest Score of a Binary Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp_l(n + 1);
    vector<int> dp_r(n + 1);

    for (int i = 1; i <= n; ++i) dp_l[i] = dp_l[i - 1] + (1 - nums[i - 1]);

    for (int i = n - 1; i >= 0; --i) dp_r[i] = dp_r[i + 1] + nums[i];

    vector<int> ans;
    int max_score = 0;
    for (int i = 0; i <= n; ++i) {
      int score = dp_l[i] + dp_r[i];

      if (score < max_score) continue;

      if (score > max_score) {
        max_score = score;
        ans.clear();
      }

      ans.push_back(i);
    }

    return ans;
  }
};
// @lc code=end
