/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;

    function<void(vector<int>&, int, int)> backtrace;
    backtrace = [&](vector<int>& cur, int sum, int index) {
      if (sum > target) return;

      if (sum == target) {
        ans.push_back(cur);
        return;
      }

      for (int i = index; i < candidates.size(); ++i) {
        cur.push_back(candidates[i]);
        backtrace(cur, sum + candidates[i], i);
        cur.pop_back();
      }
    };

    vector<int> t;
    backtrace(t, 0, 0);

    return ans;
  }
};
// @lc code=end

