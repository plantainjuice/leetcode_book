/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> mod(k, 0);
    mod[0]++;
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur = (cur + nums[i] % k + k) % k;
      cnt += mod[cur];
      ++mod[cur];
    }

    return cnt;
  }
};
// @lc code=end
