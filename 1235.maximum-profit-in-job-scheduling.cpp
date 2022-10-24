/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();

    // sort by start-time
    vector<vector<int>> jobs;
    for(int i = 0; i < n; ++i) jobs.push_back({startTime[i], endTime[i], profit[i]});
    sort(jobs.begin(), jobs.end());

    vector<int> S;
    for(int i = 0; i < n; ++i) S.push_back(jobs[i][0]);

    vector<int> memo(n, -1);
    function<int(int)> dp = [&](int i) -> int {
      if (i == n) return 0;

      // memorize
      if(memo[i] != -1) return memo[i];

      // 1. not choose current job
      int money = dp(i + 1);

      // 2. choose the next job
      int j = lower_bound(S.begin(), S.end(), jobs[i][1]) - S.begin();
      money = max(money, dp(j) + jobs[i][2]);

      return memo[i] = money;
    };

    return dp(0);
  }
};
// @lc code=end

