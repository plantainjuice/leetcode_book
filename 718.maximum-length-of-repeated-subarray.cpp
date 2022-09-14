/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> dp(n2 + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n1; ++i) {
      for (int j = n2; j > 0; --j) {
        if (nums1[i - 1] == nums2[j - 1])
          dp[j] = dp[j - 1] + 1;
        else
          dp[j] = 0;

        ans = max(ans, dp[j]);
      }
    }

    return ans;
  }

  /*
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int ans = 0;
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
  */
};
// @lc code=end

