/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();

    auto cmp = [&](int a, int b) -> bool {
      if (abs(a - x) == abs(b - x)) return a < b;

      return abs(a - x) < abs(b - x);
    };

    sort(arr.begin(), arr.end(), cmp);

    arr.resize(k);

    sort(arr.begin(), arr.end());

    return arr;
  }
};
// @lc code=end
