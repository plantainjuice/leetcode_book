/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;

    vector<int> path;
    backtrack(nums, 0, path, ans);

    return ans;
  }
private:
 void backtrack(vector<int>& nums, int index, vector<int>& path,
                vector<vector<int>>& ans) {
   if (path.size() > 1) {
     ans.push_back(path);
   }

   unordered_set<int> used;
   for (int i = index; i < nums.size(); ++i) {
     if ((!path.empty() && path.back() > nums[i]) || used.count(nums[i]) > 0)
       continue;

     used.insert(nums[i]);

     path.push_back(nums[i]);
     backtrack(nums, i + 1, path, ans);
     path.pop_back();
   }
 }
};
// @lc code=end

