/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int i = 0;
    int c = 0;
    while (i < arr.size()) {
      ++c;

      if (arr[i] == c) {
        ++i;
        continue;
      }

      --k;
      if(k == 0) return c;
    }

    return c + k;
  }
};
// @lc code=end

