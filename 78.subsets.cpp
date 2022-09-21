/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;

    vector<int> path;
    backtrace(nums, 0, path, ans);

    return ans;
  }

 private:
  void backtrace(vector<int>& nums, int index, vector<int>& path,
                 vector<vector<int>>& ans) {
    ans.push_back(path);

    for (int i = index; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtrace(nums, i + 1, path, ans);
      path.pop_back();
    }
  }
};
// @lc code=end

