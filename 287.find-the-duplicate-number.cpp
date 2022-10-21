/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int sz = nums.size();

    // f(x) -> sum(x >= n) > x
    auto f = [&](int x) -> bool {
      int cnt = 0;

      for (int n : nums)
        if (x >= n) ++cnt;

      return cnt > x;
    };

    int l = 0, r = sz;
    while (l < r) {
      int mid = (r - l) / 2 + l;
      if (f(mid))
        r = mid;
      else
        l = mid + 1;
    }

    return l;
  }

  // there must be a loop
  /*
  for exmample :134252

                   ┌───► 4──────►
                   │
                   │             5
                   │             │
  1──────►3──────► 2  ◄───────────
  */
//  public:
  // int findDuplicate(vector<int>& nums) {
  //   int fast = 0;
  //   int slow = 0;
  //   while (true) {
  //     slow = nums[slow];
  //     fast = nums[nums[fast]];
  //     if (slow == fast) break;
  //   }

  //   int slow2 = 0;
  //   while (slow2 != slow) {
  //     slow = nums[slow];
  //     slow2 = nums[slow2];
  //   }

  //   return slow;
  // }
};
// @lc code=end

