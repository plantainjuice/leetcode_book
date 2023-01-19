/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 */

// @lc code=start
class Solution {
 public:
  int findBestValue(vector<int>& arr, int target) {
    auto func = [&](int v) -> int {
      int sum = 0;
      for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > v) {
          sum += v;
        } else {
          sum += arr[i];
        }
      }

      return sum;
    };

    int l = 0, r = *max_element(arr.begin(), arr.end());
    while (l < r) {
      int mid = (r + l) / 2 + 1;
      if (func(mid) <= target) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
      
    if(abs(func(l + 1) - target) < abs(target - func(l)))
        return l + 1;
      
    return l;
  }
};
// @lc code=end

