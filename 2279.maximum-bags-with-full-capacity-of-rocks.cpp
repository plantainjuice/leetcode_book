/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution {
 public:
  int maximumBags(vector<int>& C, vector<int>& R, int A) {
    vector<int> reserved;

    for (int i = 0; i < C.size(); ++i) reserved.push_back(C[i] - R[i]);

    sort(reserved.begin(), reserved.end());

    for (int i = 0; i < reserved.size(); ++i) {
      if (reserved[i] > A) break;

      A -= reserved[i];
      reserved[i] = 0;
    }

    return std::count(reserved.begin(), reserved.end(), 0);
  }
};
// @lc code=end
