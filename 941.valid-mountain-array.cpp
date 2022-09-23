/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) return false;

    int i = 0;
    while (i < (arr.size() - 1) && arr[i] < arr[i + 1]) ++i;

    int j = arr.size() - 1;
    while (j > 0 && arr[j - 1] > arr[j]) --j;

    if (i == j && i != (arr.size() - 1) && j != 0) return true;
    return false;
  }
};
// @lc code=end

