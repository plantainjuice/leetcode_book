/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int l = 1; l <= n; ++l)
      for (int i = 1; i <= n - l + 1; ++i) {
        int j = i + l - 1;

        for (int k = i; k <= j; ++k) {
          int tmp =
              dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j];
          dp[i][j] = max(dp[i][j], tmp);
        }
      }

    return dp[1][n];
  }

  /*
  // memorize
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));

    function<int(int, int)> max_coins;
    max_coins = [&](int l, int h) {
      if (l > h) return 0;

      if (memo[l][h] > 0) return memo[l][h];

      int ans = 0;
      for (int k = l; k <= h; ++k) {
        ans = max(ans, max_coins(l, k - 1) +
                       nums[l - 1]*nums[k]*nums[h + 1] +
                       max_coins(k + 1, h));
      }

      memo[l][h] = ans;

      return ans;
    };

    return max_coins(1, n);
  }
  */
};
// @lc code=end

