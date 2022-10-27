/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> S(nums.begin(), nums.end());
    for (int n : nums) {
      if (S.find(n - 1) == S.end()) {
        int next = n + 1;
        while (S.find(next) != S.end()) ++next;

        ans = max(ans, next - n);
      }
    }

    return ans;
  }
};
// @lc code=end

