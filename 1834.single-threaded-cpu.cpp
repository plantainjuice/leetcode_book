/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    // 1. build
    using T = vector<int>;
    priority_queue<T, vector<T>, greater<T>> available;

    vector<T> v;
    for (int i = 0; i < tasks.size(); ++i)
      v.push_back({tasks[i][0], tasks[i][1], i});

    // 2. sort by enqueue_time
    sort(v.begin(), v.end());

    // 3. emulation
    int i = 0;
    long cur_time = v[0][0];
    vector<int> ans;
    while (i < tasks.size() || !available.empty()) {
      while (i < tasks.size() && cur_time >= v[i][0]) {
        available.push({v[i][1], v[i][2]});  // <process_time, index>
        ++i;
      }

      cur_time += available.top()[0];
      ans.push_back(available.top()[1]);
      available.pop();

      if(i < tasks.size() && cur_time < v[i][0] && available.empty())
        cur_time = v[i][0];
    }

    return ans;
  }
};
// @lc code=end
