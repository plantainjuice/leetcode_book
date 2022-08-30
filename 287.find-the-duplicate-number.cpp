/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
  // there must be a loop
  /*
  for exmample :134252

                   ┌───► 4──────►
                   │
                   │             5
                   │             │
  1──────►3──────► 2  ◄───────────
  */
 public:
  int findDuplicate(vector<int>& nums) {
    int fast = 0;
    int slow = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) break;
    }

    fast = 0;
    while (fast != slow) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
// @lc code=end

