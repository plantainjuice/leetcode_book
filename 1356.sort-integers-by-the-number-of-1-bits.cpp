/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    auto get_bit_count = [](int n) -> int {
      int cnt = 0;
      while (n > 0) {
        n &= n - 1;
        ++cnt;
      }
      return cnt;
    };

    auto cmp = [&](int n1, int n2) -> bool {
      int c1 = get_bit_count(n1);
      int c2 = get_bit_count(n2);

      if (c1 == c2) return n1 < n2;

      return c1 < c2;
    };

    sort(arr.begin(), arr.end(), cmp);

    return arr;
  }
};
// @lc code=end

