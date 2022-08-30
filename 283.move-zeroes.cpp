/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // frontest zero index
        int index = -1;

        for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] == 0) {
            index = index == -1 ? i : index;
            continue;
          }

          if (index != -1) {
            swap(nums[i], nums[index]);
            index++;
          }
        }
    }
};
// @lc code=end

