/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */

// @lc code=start
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    int n = arr.size();
    int half = (n + 1) / 2;

    unordered_map<int, int> m1;
    for (int i : arr) ++m1[i];

    priority_queue<int> q;
    for (auto& kv : m1) q.push(kv.second);

    int cnt = 0;
    while (half > 0) {
      ++cnt;

      int c = q.top();
      q.pop();
      half -= c;
    }

    return cnt;
  }
};
// @lc code=end

