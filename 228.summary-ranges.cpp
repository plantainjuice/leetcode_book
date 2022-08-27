/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
 vector<string> summaryRanges(vector<int>& nums) {
   vector<string> ans;
   int prev = 0;
   for (int i = 1; i <= nums.size(); ++i) {
     if (i == nums.size() || nums[i - 1] + 1 != nums[i]) {
       if (prev == i - 1)
         ans.push_back(to_string(nums[i - 1]));
       else
         ans.push_back(to_string(nums[prev]) + "->" + to_string(nums[i - 1]));
       prev = i;
     }
   }

   return ans;
 }
};
// @lc code=end

