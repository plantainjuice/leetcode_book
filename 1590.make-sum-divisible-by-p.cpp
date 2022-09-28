/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      int sum = 0;
      for(int n : nums) sum = (sum + n) % p;

      if(sum == 0) return 0;

      int ans = nums.size();
      int cur = 0;
      unordered_map<int, int> mp;
      mp[0] = -1;
      for (int i = 0; i < nums.size(); ++i) {
        cur = (cur + nums[i]) % p;
        mp[cur] = i;

        int rest = (cur - sum + p) % p;
        if(mp.find(rest) != mp.end()) ans = min(ans, i - mp[rest]);
      }

      return ans == nums.size() ? -1 : ans;
    }
};
// @lc code=end

