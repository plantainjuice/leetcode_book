/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;

    vector<int> curr;
    backtrack(k, n, 1, curr, ans);

    return ans;
  }

 private:
  void backtrack(int k, int target, int index, vector<int>& curr,
                 vector<vector<int>>& ans) {
    if (target == 0 && curr.size() == k) {
      ans.push_back(curr);
      return;
    }

    for (int i = index; i < 10; ++i) {
      if (index <= target) {
        curr.push_back(i);
        backtrack(k, target - i, i + 1, curr, ans);
        curr.pop_back();
      }
    }
  }
};
// @lc code=end

