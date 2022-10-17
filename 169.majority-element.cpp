/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int maj = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (cnt == 0) maj = nums[i];

      if (nums[i] == maj)
        cnt++;
      else
        cnt--;
    }

    return maj;
  }
};
// @lc code=end

