/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<double>> memo(n, vector<double>(k, -1));

    return dfs(nums, k - 1, 0, memo);
  }

 private:
  double dfs(vector<int>& nums, int k, int i, vector<vector<double>>& memo) {
    int n = nums.size();

    if(k == 0) 
      return double(accumulate(nums.begin() + i, nums.end(), 0)) / (n - i);

    if (memo[i][k] > 0) return memo[i][k];

    double res = 0;
    double sum = 0;
    for (int c = 1; i + c < n; ++c) {
      sum += nums[i + c - 1];
      double avg = sum / c;

      res = max(res, avg + dfs(nums, k - 1, i + c, memo));
    }

    return memo[i][k] = res;
  }
};
// @lc code=end

