/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
 public:
  double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
    vector<vector<double>> workers;
    for (int i = 0; i < Q.size(); ++i)
      workers.push_back({(double)W[i] / Q[i], (double)Q[i]});

    sort(workers.begin(), workers.end());

    double ans = DBL_MAX;
    double qsum = 0;
    priority_queue<double> pq;
    for (auto& worker : workers) {
      qsum += worker[1];
      pq.push(worker[1]);

      if (pq.size() > K) {
        qsum -= pq.top();
        pq.pop();
      }

      if (pq.size() == K) {
        ans = min(ans, qsum * worker[0]);
      }
    }

    return ans;
  }
};
// @lc code=end
