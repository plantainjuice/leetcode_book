/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
          if (val != nums[fast]) nums[slow++] = nums[fast];
        }

        return slow;
    }
};
// @lc code=end

