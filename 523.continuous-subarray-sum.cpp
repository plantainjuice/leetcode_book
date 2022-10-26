/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
 public:
  bool checkSubarraySum(vector<int>& N, int K) {
    int pre_sum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < N.size(); ++i) {
      pre_sum += N[i];

      pre_sum = pre_sum % K;

      if (pre_sum == 0 && i) return true;

      if (mp.find(pre_sum) != mp.end()) {
        // at least 2 element
        if (i - mp[pre_sum] > 1) return true;

      } else {
        mp[pre_sum] = i;
      }

    }

    return false;
  }
};
// @lc code=end

