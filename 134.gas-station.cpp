/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    int cur_sum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      cur_sum += gas[i] - cost[i];

      if (cur_sum < 0) {
        start = i + 1;
        cur_sum = 0;
      }
    }

    if (sum < 0) return -1;

    return start;
  }
};
// @lc code=end

