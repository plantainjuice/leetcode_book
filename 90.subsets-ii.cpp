/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
 vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   sort(nums.begin(), nums.end());

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
     if (i > index && nums[i - 1] == nums[i]) continue;

     path.push_back(nums[i]);
     backtrace(nums, i + 1, path, ans);
     path.pop_back();
   }
 }
};
// @lc code=end

