/*
 * @lc app=leetcode id=1738 lang=cpp
 *
 * [1738] Find Kth Largest XOR Coordinate Value
 */

// @lc code=start
class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& M, int k) {
    int n = M.size(), m = M[0].size();
    priority_queue<int, vector<int>, greater<int>> pq;

    // 1. left-right
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        M[i][j] = M[i][j - 1] ^ M[i][j];
      }
    }

    // 2. top-down
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        M[j][i] = M[j - 1][i] ^ M[j][i];
      }
    }

    // 3. find the k-th max
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pq.size() < k)
          pq.push(M[i][j]);
        else {
          if (M[i][j] > pq.top()) {
            pq.pop();
            pq.push(M[i][j]);
          }
        }
      }
    }

    return pq.top();
  }
};
// @lc code=end
