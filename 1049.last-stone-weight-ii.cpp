/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);

    int target = sum / 2;
    vector<int> dp(target + 1);

    for (int i = 0; i < stones.size(); ++i) {
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return (sum - dp[target]) - dp[target];

  }
};
// @lc code=end

