/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());

    vector<int> hash(101, 0);
    for (int i = tmp.size() - 1; i >= 0; --i) {
      hash[tmp[i]] = i;
    }

    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      ans[i] = hash[nums[i]];
    }

    return ans;
  }
};
// @lc code=end

