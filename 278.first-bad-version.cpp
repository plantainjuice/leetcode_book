/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    function<int(int, int)> b_search;

    b_search = [&](int l, int h) -> int {
      if (l == h) return l;

      int mid = l + (h - l) / 2;

      if (isBadVersion(mid))
        return b_search(l, mid);
      else
        return b_search(mid + 1, h);
    };

    return b_search(1, n);
  }
};
// @lc code=end

