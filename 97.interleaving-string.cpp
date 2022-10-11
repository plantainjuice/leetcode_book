/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
// bottom-up
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();
    if (n1 + n2 != n3) return false;

    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n1; ++i) {
      dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i-1][0];
    }

    for (int j = 1; j <= n2; ++j) {
      dp[0][j] = s2[j - 1] == s3[j - 1] && dp[0][j-1];
    }

    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        dp[i][j] = s1[i - 1] == s3[i + j - 1] && dp[i-1][j];

        // prune
        if(dp[i][j] == true) continue;

        dp[i][j] = s2[j - 1] == s3[i + j - 1] && dp[i][j-1];
      }
    }

    return dp[n1][n2];
  }
};

// recursion & memorization
// class Solution {
//  public:
//   bool isInterleave(string s1, string s2, string s3) {
//     int n1 = s1.size();
//     int n2 = s2.size();
//     int n3 = s3.size();
//     if (n1 + n2 != n3) return false;

//     vector<vector<int>> memo(n1, vector<int>(n2, -1));

//     return dp(s1, s2, s3, 0, 0, memo);
//   }

//  private:
//   bool dp(const string& s1, const string& s2, const string& s3, int i, int j, vector<vector<int>>& memo) {
//     if (i == s1.size() && j == s2.size()) return true;

//     if (memo[i][j] != -1) return bool(memo[i][j]);

//     bool res = false;
//     if (i < s1.size() && s1[i] == s3[i + j]) {
//       res = dp(s1, s2, s3, i + 1, j, memo);
//     }

//     if (j < s2.size() && s2[j] == s3[i + j]) {
//       res = res || dp(s1, s2, s3, i, j + 1, memo);
//     } 

//     return memo[i][j] = int(res);
//   }
// };
// @lc code=end

