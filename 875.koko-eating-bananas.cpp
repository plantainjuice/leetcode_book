/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = 1e9;

    auto cal_eating_hours = [&](int k) -> int {
      int total = 0;

      for (int p : piles) total += p % k == 0 ? (p / k) : (p / k + 1);

      return total;
    };

    while (low < high) {
      int mid = low + (high - low) / 2;

      if (cal_eating_hours(mid) > h) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return low;
  }
};
// @lc code=end

