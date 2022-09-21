/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
   vector<vector<int>> ans;
   vector<bool> used(candidates.size(), false);

   function<void(vector<int>&, int, int)> backtrace;
   backtrace = [&](vector<int>& cur, int sum, int index) {
     if (sum > target) return;

     if (sum == target) {
       ans.push_back(cur);
       return;
     }

     for (int i = index; i < candidates.size(); ++i) {
       // remove duplicate
       if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
         continue;

       cur.push_back(candidates[i]);
       used[i] = true;
       backtrace(cur, sum + candidates[i], i + 1);
       cur.pop_back();
       used[i] = false;
     }
   };

   sort(candidates.begin(), candidates.end());
   vector<int> c;
   backtrace(c, 0, 0);

   return ans;
 }
};
// @lc code=end

