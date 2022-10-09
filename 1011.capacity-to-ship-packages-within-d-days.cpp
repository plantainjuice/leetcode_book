/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    if(days == 1) return sum;

    int low = *max_element(weights.begin(), weights.end());
    int high = sum;

    auto cal_days = [&](int capacity) -> int {
      int total = 0;

      int load = 0;
      for (int i = 0; i < weights.size();) {
        // overload
        if (load + weights[i] > capacity) {
          load = 0;
          ++total;
        } else {
          load = load + weights[i];
          ++i;
        }
      }

      // has rest
      if (load != 0) ++total;

      return total;
    };

    while (low < high) {
      int mid = low + (high - low) / 2;

      if (cal_days(mid) > days) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
// @lc code=end

