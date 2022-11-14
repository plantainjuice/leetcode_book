/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int len = tasks.size();
    vector<int> task_cnt(26, 0);

    int max_cnt = 0;
    for (char t : tasks) {
      task_cnt[t - 'A']++;
      max_cnt = max(max_cnt, task_cnt[t - 'A']);
    }

    int cost = (max_cnt - 1) * (n + 1);

    for (int c : task_cnt)
      if (c == max_cnt) cost++;

    return max(len, cost);
  }
};
// @lc code=end
